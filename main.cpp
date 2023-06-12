//
// Created by Christian on 25/05/2023.
//

#include "Spreadsheet.h"
#include <curses.h>
#include <memory>

void drawSpreadsheet(const Spreadsheet& spreadsheet) {
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

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int r = 10;
    int c = 10;
    Spreadsheet spreadsheet(r, c);

    int row = 0;
    int col = 0;
    int ch;
    double value = 0;
    bool valid = true;
    std::string check;

    int boxCurrentHeight = 4;
    int boxCurrentWidth = 30;
    int boxCurrentStartY = r * 2 + 2;
    int boxCurrentStartX = 0;
    WINDOW* boxCurrent = newwin(boxCurrentHeight, boxCurrentWidth, boxCurrentStartY, boxCurrentStartX);

    int boxInfoHeight = 7;
    int boxInfoWidth = 62;
    int boxInfoStartY = r * 2 + 2;
    int boxInfoStartX = 40;
    WINDOW* boxInfo = newwin(boxInfoHeight, boxInfoWidth, boxInfoStartY, boxInfoStartX);

    wclear(boxCurrent);
    mvwprintw(boxCurrent, 1, 1, "Value: %.2f", value);
    mvwprintw(boxCurrent, 2, 1, "Formula: %s", " ");
    box(boxCurrent, 0, 0);

    wclear(boxInfo);
    mvwprintw(boxInfo, 1, 1, "Usa le freccette direzionali per muoverti tra le celle");
    mvwprintw(boxInfo, 2, 1 , "Premi: ");
    mvwprintw(boxInfo, 3, 1, "'s' per inserire un valore numerico");
    mvwprintw(boxInfo, 4, 1, "'f' per inserire una formula");
    mvwprintw(boxInfo, 5, 1, "'q' per uscire");
    box(boxInfo, 0, 0);

    drawSpreadsheet(spreadsheet);
    move(2, 5);
    wrefresh(boxCurrent);
    wrefresh(boxInfo);

    while ((ch = getch()) != 'q') {
        switch (ch) {
            case KEY_UP:
                if (row > 0) {
                    row--;
                }
                break;
            case KEY_DOWN:
                if (row < spreadsheet.getRows() - 1) {
                    row++;
                }
                break;
            case KEY_LEFT:
                if (col > 0) {
                    col--;
                }
                break;
            case KEY_RIGHT:
                if (col < spreadsheet.getColumns() - 1) {
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
            default:
                break;
        }

        drawSpreadsheet(spreadsheet);
        move(row + row + 2, col * 10 + 5);

        wclear(boxCurrent);
        box(boxCurrent, 0, 0);
        box(boxInfo, 0, 0);
        //TODO se una cella non ha valori assegnati non considerarla nella formula
        if (valid) {
            double cellValue = spreadsheet.getCellValue(row, col);
            mvwprintw(boxCurrent, 1, 1, "Value: %.2f", cellValue);
            std::string cellFormula = spreadsheet.getCellFormula(row, col);
            mvwprintw(boxCurrent, 2, 1, "Formula: %s", cellFormula.c_str());
        }
        else {
            mvwprintw(boxCurrent, 1, 1, "Invalid Value %s !", check.c_str());
            valid = true;
        }
        wrefresh(boxCurrent);
        wrefresh(boxInfo);
    }

    endwin();
    delwin(boxCurrent);
    delwin(boxInfo);

    return 0;
}