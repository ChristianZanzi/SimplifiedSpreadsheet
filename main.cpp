//
// Created by Christian on 25/05/2023.
//

#include <curses.h>
#include <memory>
#include <list>
#include "Spreadsheet.h"

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
            mvprintw(row + row + 1 + 1, col * 10 + 3 + 1, "%.2f", value);
            mvprintw(row + row + 1 + 1, col * 10 + 10 + 1, "|");
        }
    }

    refresh();
}

int main() {
    // Inizializza ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Crea un'istanza dello Spreadsheet
    int r = 10;
    int c = 10;
    Spreadsheet spreadsheet(r, c);

    // Posizione iniziale del cursore
    int row = 0;
    int col = 0;
    int ch;
    double value = 0.0;
    bool valid = true;

    // Crea una nuova finestra per il box
    int boxHeight = 4;
    int boxWidth = 30;
    int boxStartY = r * 2 + 1 + 1;  // Posizione verticale del box
    int boxStartX = 0;  // Posizione orizzontale del box
    WINDOW* boxWin = newwin(boxHeight, boxWidth, boxStartY, boxStartX);

    // Disegna il box
    box(boxWin, 0, 0);
    mvwprintw(boxWin, 1, 1, "Value: %.2f", 0);
    mvwprintw(boxWin, 2, 1, "Formula: %s", " ");

    drawSpreadsheet(spreadsheet);
    move(2, 5);
    wrefresh(boxWin);

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
                // Imposta il valore della cella corrente
                mvprintw(row + row + 1 + 1, col * 10 + 1, "        ");
                mvprintw(row + row + 1 + 1, col * 10 + 1, "> ");
                echo();
                char valueString[20];  // Dimensione maggiore per consentire numeri più grandi
                getstr(valueString);
                noecho();
                //value = atof(valueString);
                try {
                    value = atof(valueString);
                    spreadsheet.setCellValue(row, col, value);
                } catch (const std::invalid_argument& e) {
                    valid = false;
                    mvwprintw(boxWin, 1, 1, "INVALID VALUE!: %s", valueString);
                    refresh();
                } catch (const std::out_of_range& e) {
                    valid = false;
                    mvwprintw(boxWin, 1, 1, "INVALID VALUE!: %s", valueString);
                    wrefresh(boxWin);
                }
                /*if(value){
                    spreadsheet.setCellValue(row, col, value);
                }
                else{
                    mvprintw(4, 10, "INVALID VALUE!: %s", valueString);
                    refresh();
                }*/
                break;
            case 'f':
                // Imposta la formula per la cella corrente
                mvprintw(row + row + 1 + 1, col * 10 + 1, "        ");
                mvprintw(row + row + 1 + 1, col * 10 + 1, "> ");
                echo();
                char formula[20];
                getstr(formula);
                noecho();
                spreadsheet.setCellFormula(row, col, formula);
                break;
            default:
                break;
        }

        // Disegna lo Spreadsheet
        drawSpreadsheet(spreadsheet);

        // Sposta il cursore alla posizione corrente
        move(row + row + 1 + 1, col * 10 + 4 + 1);

        /// Stampa il valore o la formula della cella corrente nel box
        /*box(boxWin, 0, 0);
        wrefresh(boxWin);
        double cellValue = spreadsheet.getCellValue(row, col);
        mvwprintw(boxWin, 1, 1, "Value: %.2f", cellValue);
        std::string cellFormula = spreadsheet.getCellFormula(row, col);
        mvwprintw(boxWin, 2, 1, "Formula: %s", cellFormula.c_str());

        wrefresh(boxWin);*/
        wclear(boxWin);
        box(boxWin, 0, 0);
        if(valid){
            double cellValue = spreadsheet.getCellValue(row, col);
            mvwprintw(boxWin, 1, 1, "Value: %.2f", cellValue);
            std::string cellFormula = spreadsheet.getCellFormula(row, col);
            mvwprintw(boxWin, 2, 1, "Formula: %s", cellFormula.c_str());
        }
        else {
            mvwprintw(boxWin, 1, 1, "Value: %s", "invalid value");
            valid = true;
        }
        wrefresh(boxWin);

    }
    // Termina ncurses
    endwin();
    delwin(boxWin);

    return 0;
}