//
// Created by chri on 12/06/23.
//

#include "UserInterface.h"

void UserInterface::drawSpreadsheet(const Spreadsheet& spreadsheet) {
    clear();

    int rows = spreadsheet.getRows();
    int columns = spreadsheet.getColumns();

    for (int row = 0; row < rows; row++) {
        mvprintw(row + row + 2, 0, "%d", row);
    }
    for (int col = 0; col < columns; col++) {
        mvprintw(0, col * 10 + 5, "%d", col);
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            double value = spreadsheet.getCellValue(row, col);
            mvprintw(row + row + 1, col * 10 + 1, "+----------");
            mvprintw(row + row + 1 + 1, col * 10 + 1, "|");
            if (spreadsheet.hasCellValue(row, col))
                mvprintw(row + row + 1 + 1, col * 10 + 4, "%.2f", value);
            mvprintw(row + row + 1 + 1, col * 10 + 11, "|");
        }
    }

    for (int col = 0; col < columns; col++) {
        mvprintw(rows + rows + 1, col * 10 + 1, "+----------");
    }

    refresh();
}

UserInterface::UserInterface(Spreadsheet& spreadsheet) : spreadsheet(spreadsheet),
            rows(spreadsheet.getRows()), cols(spreadsheet.getColumns()), value(0), valid(true) {
    setCellContentBox(4, 30, rows * 2 + 2, 0);
    setInfoBox(7, 62, rows * 2 + 2, 40);

    wclear(cellContentBox);
    mvwprintw(cellContentBox, 1, 1, "Value: %.2f", value);
    mvwprintw(cellContentBox, 2, 1, "Formula: %s", " ");
    box(cellContentBox, 0, 0);

    wclear(infoBox);
    mvwprintw(infoBox, 1, 1, "Usa le freccette direzionali per muoverti tra le celle");
    mvwprintw(infoBox, 2, 1 , "Premi: ");
    mvwprintw(infoBox, 3, 1, "'s' per inserire un valore numerico");
    mvwprintw(infoBox, 4, 1, "'f' per inserire una formula");
    mvwprintw(infoBox, 5, 1, "'q' per uscire");
    box(infoBox, 0, 0);

    drawSpreadsheet(spreadsheet);
    move(2, 5);
    wrefresh(cellContentBox);
    wrefresh(infoBox);
}

UserInterface::~UserInterface() {
    delwin(cellContentBox);
    delwin(infoBox);
}

void UserInterface::setCellContentBox(int height, int width, int startY, int startX) {
    UserInterface::cellContentBox = newwin(height, width, startY, startX);
}

void UserInterface::setInfoBox(int height, int width, int startY, int startX) {
    UserInterface::infoBox = newwin(height, width, startY, startX);
}

void UserInterface::handleUserInput(int ch, int& row, int& col) {
    switch (ch) {
        case KEY_UP:
            if (row > 0) {
                row--;
            }
            break;
        case KEY_DOWN:
            if (row < rows - 1) {
                row++;
            }
            break;
        case KEY_LEFT:
            if (col > 0) {
                col--;
            }
            break;
        case KEY_RIGHT:
            if (col < cols - 1) {
                col++;
            }
            break;
        case 's':
            mvprintw(row + row + 2, col * 10 + 1, "        ");
            mvprintw(row + row + 2, col * 10 + 1, " > ");
            echo();
            char valueString[20];
            getstr(valueString);
            check = valueString;
            noecho();
            value = atof(valueString);   //atof, data una stringa di byte in ingresso restituisce un numero in virgola mobile.
            if (check != "0" && !value)
                valid = false;
            else
                spreadsheet.setCellValue(row, col, value);
            break;
        case 'f':
            mvprintw(row + row + 1 + 1, col * 10 + 1, "        ");
            mvprintw(row + row + 1 + 1, col * 10 + 1, " > ");
            echo();
            char formula[20];
            getstr(formula);
            noecho();
            check = spreadsheet.getCellFormula(row, col);
            spreadsheet.setCellFormula(row, col, formula);
            if (spreadsheet.getCellFormula(row,col) ==  check || spreadsheet.getCellFormula(row,col) == "none") {
                valid = false;
                check = formula;
            }
            break;
        case 'c':
            mvprintw(row + row + 1 + 1, col * 10 + 1, "        ");
            spreadsheet.clearCell(row, col);
            break;
        default:
            break;
    }
}

void UserInterface::run() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int ch;
    int row = 0;
    int col = 0;

    while ((ch = getch()) != 'q') {
        handleUserInput(ch, row, col);

        drawSpreadsheet(spreadsheet);
        move(row + row + 2, col * 10 + 5);

        wclear(cellContentBox);
        box(cellContentBox, 0, 0);
        box(infoBox, 0, 0);

        if (valid) {
            double cellValue = spreadsheet.getCellValue(row, col);
            mvwprintw(cellContentBox, 1, 1, "Value: %.2f", cellValue);
            std::string cellFormula = spreadsheet.getCellFormula(row, col);
            mvwprintw(cellContentBox, 2, 1, "Formula: %s", cellFormula.c_str());
        }
        else {
            mvwprintw(cellContentBox, 1, 1, "Invalid Value %s !", check.c_str());
            valid = true;
        }
        wrefresh(cellContentBox);
        wrefresh(infoBox);
    }
}