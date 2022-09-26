#include <gtkmm.h>
#include <iostream>

class Window : public Gtk::Window {
public:
    Gtk::VBox vbox;
    Gtk::Label first_name_label = Gtk::Label("First name");
    Gtk::Entry first_name_entry;
    Gtk::Label last_name_label = Gtk::Label("Last name");
    Gtk::Entry last_name_entry;
    Gtk::Button button;
    Gtk::Label combination;

    Window() {
        button.set_label("Combine names");
        button.set_sensitive(false);
        
        vbox.pack_start(first_name_label);
        vbox.pack_start(first_name_entry);
        vbox.pack_start(last_name_label);
        vbox.pack_start(last_name_entry);
        vbox.pack_start(button);
        vbox.pack_start(combination);

        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets

        auto update_button = [this]() {
            if (check(first_name_entry.get_text(), last_name_entry.get_text())) {
                button.set_sensitive(true);
            } 
            else {
                button.set_sensitive(false);
            }
        };

        first_name_entry.signal_changed().connect(update_button);
        last_name_entry.signal_changed().connect(update_button);

        button.signal_clicked().connect([this]() {
            combination.set_text("Names combined: " + first_name_entry.get_text() + " " + last_name_entry.get_text());
        });
    }

    bool check(std::string first_name, std::string last_name) {
        if (first_name != "" && last_name != "") return true;
        return false;
    }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  window.set_title("Task 2");
  gtk_main.run(window);
}
