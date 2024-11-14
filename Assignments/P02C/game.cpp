#include <locale.h>
#include <ncurses.h>

#include "button_class.hpp"
#include "color_class.hpp"
#include "dice_class.hpp"
#include "grid_class.hpp"
#include "input_class.hpp"
#include "logger_class.hpp"
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class Player {
    string name;
    int score;

   public:
    Player(string n) : name(n), score(0) {}
    void addScore(int s) { score += s; }
    int getScore() { return score; }
    string getName() { return name; }
};

// class Game {

// };

int main() {
    srand(time(0));
    setlocale(LC_ALL, "");  // Enable Unicode support
    initscr();
    cbreak();
    noecho();
    curs_set(0);  // Hide the cursor
    clear();
    refresh();

    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    start_color();

    colorful();

    Logger::setFilePath("log.txt");

    //made an attempt to change the property of the text from the input_class.hpp file but had trouble with static
    //Input::setTextColor(7);

    int rows, cols, size;
    int ch;

    getmaxyx(stdscr, rows, cols);

    //changed text to CLICK
    string text = "CLICK";

    size = strlen(text.c_str()) + 2;

    Logger::log("vals", vector<int>({size, 3, (rows / 2), ((cols - size) / 2)}));

    // Button button(text, 2, 1, Frame({size, 3, (rows / 2), ((cols - size) / 2)}));
    Button button(text, 13, 30, Frame({3, size, 10, 15})); //changed some properties of the button such as on and off colors
    button.draw_button();

    Grid grid(1, 10);
    grid.refreshGrid();

    DiceViz dice(3, 30);

    dice.setBorderColor(9); //changed the border color to red
    dice.setDotColor(7);    //changed dot color to silver

    while (true) {
        //added logic for the program to quit from the p key as well. this was me testing the key logic and considering adding a pause feature in the future
        if (ch == 'q' || ch == 'Q' || ch == 'p' || ch == 'P') {
            break;
        } else if (ch == KEY_MOUSE) {
            MEVENT event;
            Logger::log("Mouse pressed", "true");
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_CLICKED) {
                    Logger::log("clicked", vector<int>({event.y, event.x}));
                    if (button.clicked(event.y, event.x)) {
                        button.draw_button();
                        Logger::log("drawing button", "true");
                        dice.animate_dice(15);      //Reduced roll time to 15
                        dice.draw_dice(dice.getLastDiceValue());
                        button.toggle();
                    }
                    if (grid.clicked(event.y, event.x - 1)) {
                        Logger::log("clicked grid", "true");
                        dice.clear();
                        grid.addValue(event.y, event.x - 1, dice.getLastDiceValue());  // Mark click location
                        grid.refreshGrid();
                    }
                }
            }
        }
        Logger::log("Key pressed", to_string(ch));
        button.draw_button();
        refresh();
        ch = getch();
    }

    // while (true) {
    //     // mvprintw(rows / 2, (cols / 2) - strlen(text.c_str()), text.c_str());
    //     ch = getch();

    //     if (ch == 'q' || ch == 'Q') {
    //         break;
    //     } else if (ch == KEY_MOUSE) {
    //         MEVENT event;
    //         Logger::log("Mouse pressed", "true");
    //         if (getmouse(&event) == OK) {
    //             if (event.bstate & BUTTON1_CLICKED) {
    //                 Logger::log("clicked", vector<int>({event.y, event.x}));
    //                 if (button.clicked(event.y, event.x)) {
    //                     button.draw_button();
    //                     Logger::log("drawing button", "true");
    //                     dice.animate_dice(30);
    //                     // dice.refresh();
    //                 }
    //                 if (grid.clicked(event.y, event.x - 1)) {
    //                     Logger::log("clicked grid", "true");
    //                     grid.addValue(event.y, event.x, rand() % 6 + 1);  // Mark click location
    //                 }
    //             }
    //         }
    //     }
    //     Logger::log("Key pressed", to_string(ch));
    //     button.draw_button();
    //     refresh();
    // }
    clear();
    endwin();
    return 0;
}