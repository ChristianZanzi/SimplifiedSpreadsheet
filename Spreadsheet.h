//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_SPREADSHEET_H
#define SIMPLIFIEDSPREADSHEET_SPREADSHEET_H

#include "Cell.h"
#include <list>
#include <string>
#include <memory>

class Spreadsheet {
public:
    Spreadsheet(int numRows, int numColumns);
    ~Spreadsheet() = default;

    int getRows() const;
    void setRows(int rows);

    int getColumns() const;
    void setColumns(int columns);

    void setCellValue(int row, int column, double value);
    double getCellValue(int row, int column) const;

    void setCellFormula(int row, int column, std::string formula);
    std::string getCellFormula(int row, int column) const;

    std::list<std::string> parseFormulaString(std::string& formula);

private:
    int rows;
    int columns;
    std::unique_ptr<std::unique_ptr<Cell[]>[]> matrix;
    static const char CHAR_TO_NUMBER = '0';
    static const char EMPTY_SPACE = ' ';
    static const char COMMA = ',';

    bool contains(std::list<std::string> list, std::string str);

};

#endif //SIMPLIFIEDSPREADSHEET_SPREADSHEET_H
