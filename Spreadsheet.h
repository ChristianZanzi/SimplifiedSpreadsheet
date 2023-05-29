//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_SPREADSHEET_H
#define SIMPLIFIEDSPREADSHEET_SPREADSHEET_H

#include "Cell.h"
#include <list>
#include <string>

class Spreadsheet {
public:
    Spreadsheet(int numRows, int numColumns);

    ~Spreadsheet();

    void setCellValue(int row, int column, double value);
    double getCellValue(int row, int column) const;
    void setCellFormula(int row, int column, std::string& formula);

private:
    int rows;
    int columns;
    Cell** matrix;
};


#endif //SIMPLIFIEDSPREADSHEET_SPREADSHEET_H
