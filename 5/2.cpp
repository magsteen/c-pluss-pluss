#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

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

		virtual string symbol() const = 0;
	};

	class King : public Piece {
	public:
		King(const Color color) : Piece(color) {}
		~King() {};

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
		~Knight() {};
		
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

	ChessBoard() {
		// Initialize the squares stored in 8 columns and 8 rows:
		squares.resize(8);
		for (auto &square_column : squares)
			square_column.resize(8);
	}

	/// 8x8 squares occupied by 1 or 0 chess pieces
	vector<vector<unique_ptr<Piece>>> squares;

	/// Move a chess piece if it is a valid move.
	/// Does not test for check or checkmate.
	bool move_piece(const std::string &from, const std::string &to) {
		int from_x = from[0] - 'a';
		int from_y = stoi(string() + from[1]) - 1;
		int to_x = to[0] - 'a';
		int to_y = stoi(string() + to[1]) - 1;

		auto &piece_from = squares[from_x][from_y];
		if (piece_from) {
			if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
			cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
			auto &piece_to = squares[to_x][to_y];
			if (piece_to) {
				if (piece_from->color != piece_to->color) {
				cout << piece_to->type() << " is being removed from " << to << endl;
				if (auto king = dynamic_cast<King *>(piece_to.get()))
					cout << king->color_string() << " lost the game" << endl;
				} else {
				// piece in the from square has the same color as the piece in the to square
				cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
				return false;
				}
			}
			piece_to = move(piece_from);
			return true;
			} else {
			cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
			return false;
			}
		} else {
			cout << "no piece at " << from << endl;
			return false;
		}
	}

	void draw() {
		std::cout << " A B C D E F G H" << std::endl;
		for (int i = 0; i < 8; i++) {
			std::cout << i+1;
			for (int j = 0; j < 8; j++) {
				if (squares[i][j]) std::cout << squares[i][j]->symbol();
				else if (i % 2 == j % 2) std::cout << "🮘";
				else std::cout << "🮐";
			}
			std::cout << std::endl;
		}
	}
};

int main() {
	ChessBoard board;

	board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
	board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
	board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

	board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
	board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
	board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

	cout << "Invalid moves:" << endl;
	board.move_piece("e3", "e2");
	board.move_piece("e1", "e3");
	board.move_piece("b1", "b2");
	cout << endl;

	cout << "A simulated game:" << endl;
	vector<tuple<string, string>> success_game = {
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

	std::cout << "Initial board state: " << std::endl; 
	board.draw();
	for (auto &move : success_game) {
		if (board.move_piece(get<0>(move), get<1>(move))) board.draw();
	}
	std::cout << "Game is finished." << std::endl;

	cout << endl;
}
