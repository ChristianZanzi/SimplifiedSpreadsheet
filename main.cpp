//
// Created by Christian on 25/05/2023.
//

#include "Spreadsheet.h"
#include "UserInterface.h"
#include <curses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int r = 10;
    int c = 10;
    Spreadsheet spreadsheet(r, c);

    UserInterface userInterface(spreadsheet);
    userInterface.run();

    endwin();

    return 0;
}