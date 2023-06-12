//
// Created by chri on 12/06/23.
//

#ifndef SIMPLIFIEDSPREADSHEET_USERINTERFACE_H
#define SIMPLIFIEDSPREADSHEET_USERINTERFACE_H

#include "Spreadsheet.h"
#include <curses.h>
#include <memory>

class UserInterface {
public:
    explicit UserInterface(Spreadsheet& spreadsheet);
    ~UserInterface();

    void setCellContentBox(int height, int width, int startY, int startX);

    void setInfoBox(int height, int width, int startY, int startX);

    void drawSpreadsheet(const Spreadsheet& spreadsheet);

    void handleUserInput(int ch, int& row, int& col);

    void run();

private:
    Spreadsheet& spreadsheet;
    WINDOW* cellContentBox;
    WINDOW* infoBox;
    int rows;
    int cols;
    double value;
    bool valid;
    std::string check;
};


#endif //SIMPLIFIEDSPREADSHEET_USERINTERFACE_H
