//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_SPREADSHEET_H
#define SIMPLIFIEDSPREADSHEET_SPREADSHEET_H

#include "Cell.h"
#include <list>
#include <vector>
#include <string>
#include <memory>

class Spreadsheet {
public:
    Spreadsheet(int numRows, int numColumns);
    ~Spreadsheet() = default;

    int getRows() const;

    int getColumns() const;

    bool hasCellValue(int row, int column) const;

    void setCellValue(int row, int column, double value);
    double getCellValue(int row, int column) const;

    void setCellFormula(int row, int column, std::string formula);
    std::string getCellFormula(int row, int column) const;

    std::list<std::string> parseFormulaString(std::string& formula);

    void clearCell(int row, int column);

    bool hasCircularReference(std::shared_ptr<Cell> observedCell, std::shared_ptr<Cell> observerCell);

private:
    int rows;
    int columns;
    std::vector<std::vector<std::shared_ptr<Cell>>> matrix;
    static const char CHAR_TO_NUMBER = '0';
    static const char EMPTY_SPACE = ' ';
    static const char COMMA = ',';

    bool contains(std::list<std::string> list, std::string str);
    //TODO controllare la costanza,
};

#endif //SIMPLIFIEDSPREADSHEET_SPREADSHEET_H
