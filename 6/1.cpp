#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

class ChessBoard {
public:
	enum class Color { WHITE,BLACK };

	class Piece {
	public:
		Piece(Color color) : color(color) {}
		virtual ~Piece() {}

		Color color;
		std::string color_string() const {
			if (color == Color::WHITE)
				return "white";
			else
				return "black";
		}

		/// Return color and type of the chess piece
		virtual std::string type() const = 0;

		/// Returns true if the given chess piece move is valid
		virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

		virtual std::string symbol() const = 0;
	};

	class King : public Piece {
	public:
		King(const Color color) : Piece(color) {}

		std::string type() const override {
			return color_string() + " king";
		}

		bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
			bool rtn = false;
			if (abs(from_x - to_x) <= 1 && abs(from_y - to_y) <= 1) rtn = true;
			return rtn;
		}

		std::string symbol() const override {
			if (color == Color::BLACK) {
				return "♚";
			} else {
				return "♔";
			}
		}
	};

	class Knight : public Piece {
	public:
		Knight(const Color color) : Piece(color) {}
		
		std::string type() const override {
			return color_string() + " knight";
		}

		bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
			bool rtn = false;
			if (abs(from_x - to_x)  == 2 && abs(from_y - to_y) == 1) rtn = true;
			if (abs(from_x - to_x)  == 1 && abs(from_y - to_y) == 2) rtn = true;
			return rtn;
		}

		std::string symbol() const override {
			if (color == Color::BLACK) {
				return "♞";
			} else {
				return "♘";
			}
		}
	};

	std::function<void(const Piece &piece, const std::string &from, const std::string &to)> on_piece_move;
	std::function<void(const Piece &piece, const std::string &square)> on_piece_removed;
	std::function<void(Color color)> on_lost_game;
	std::function<void(const Piece &piece, const std::string &from, const std::string &to)> on_piece_move_invalid;
	std::function<void(const std::string &square)> on_piece_move_missing;

	ChessBoard() {
		// Initialize the squares stored in 8 columns and 8 rows:
		squares.resize(8);
		for (auto &square_column : squares)
			square_column.resize(8);
	}

	/// 8x8 squares occupied by 1 or 0 chess pieces
	std::vector<std::vector<std::unique_ptr<Piece>>> squares;

	/// Move a chess piece if it is a valid move.
	/// Does not test for check or checkmate.
	bool move_piece(const std::string &from, const std::string &to) {
		int from_x = from[0] - 'a';
		int from_y = stoi(std::string() + from[1]) - 1;
		int to_x = to[0] - 'a';
		int to_y = stoi(std::string() + to[1]) - 1;

		auto &piece_from = squares[from_x][from_y];
		if (piece_from) {
			if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
				if (on_piece_move) on_piece_move(*piece_from, from, to);
				auto &piece_to = squares[to_x][to_y];
				if (piece_to) {
					if (piece_from->color != piece_to->color) {
					if (on_piece_removed) on_piece_removed(*piece_to, to);
					if (auto king = dynamic_cast<King *>(piece_to.get()))
						if (on_lost_game) on_lost_game(king->color);
					} else {
					// piece in the from square has the same color as the piece in the to square
						if (on_piece_move_invalid) on_piece_move_invalid(*piece_from, from, to);
						return false;
					}
				}
				piece_to = move(piece_from);
				if (after_piece_move)
					after_piece_move();
				return true;
			} else {
				if (on_piece_move_invalid) on_piece_move_invalid(*piece_from, from, to);
				return false;
			}
		} else {
			if (on_piece_move_missing) on_piece_move_missing(from);
			return false;
		}
	}

	std::function<void()> after_piece_move;
};


class ChessBoardPrint {
private:
	ChessBoard& board;
public:
	ChessBoardPrint(ChessBoard& _board) : board(_board) {
		// Skriv lambda utrykk her
		board.on_piece_move = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to) {
			std::cout << piece.type() << " is moving from " << from << " to " << to << std::endl;
		};
		board.on_piece_removed = [](const ChessBoard::Piece &piece, const std::string &square) {
			std::cout << piece.type() << " is being removed from " << square << std::endl;
		};
		board.on_lost_game = [](ChessBoard::Color color) {
 			std::string color_string = color == ChessBoard::Color::WHITE ? "White" : "Black";
            std::cout << color_string << " lost the game" << std::endl;
		};
		board.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const std::string &from, const std::string &to) {
			std::cout << "can not move " << piece.type() << " from " << from << " to " << to << std::endl;
		};
		board.on_piece_move_missing = [](const std::string &square) {
			std::cout << "no piece at " << square << std::endl;
		};

		board.after_piece_move = [this]() {
			std::cout << "  A  B  C  D  E  F  G  H " << std::endl;
			for (int i = 0; i < 8; i++) {
				std::cout << i+1;
				for (int j = 0; j < 8; j++) {
					if (this->board.squares[j][i]) std::cout << " " + this->board.squares[j][i]->symbol() + " ";
					else if (i % 2 == j % 2) std::cout << "░░░";
					else std::cout << "▒▒▒";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl; //Spacing
		};
	}
};


int main() {
	ChessBoard board;

	ChessBoardPrint print(board);

	board.squares[4][0] = std::make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
	board.squares[1][0] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
	board.squares[6][0] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

	board.squares[4][7] = std::make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
	board.squares[1][7] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
	board.squares[6][7] = std::make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

	std::cout << "Invalid moves:" << std::endl;
	board.move_piece("e3", "e2");
	board.move_piece("e1", "e3");
	board.move_piece("b1", "b2");
	std::cout << std::endl;

	std::cout << "A simulated game:" << std::endl;
	std::vector<std::tuple<std::string, std::string>> success_game = {
		{"e1", "e2"}, 
		{"g8", "h6"}, 
		{"b1", "c3"},
		{"h6", "g8"},
		{"c3", "d5"},
		{"g8", "h6"},
		{"d5", "f6"},
		{"h6", "g8"},
		{"f6", "e8"}
	};
	for (auto &move : success_game) {
		board.move_piece(std::get<0>(move), std::get<1>(move));
	};
	std::cout << "Game is finished." << std::endl;

	std::cout << std::endl;
}
