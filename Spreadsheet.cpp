//
// Created by Christian on 25/05/2023.
//

#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(int numRows, int numColumns) : rows(numRows), columns(numColumns),
        matrix(rows, std::vector<std::shared_ptr<Cell>>(columns)){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = std::make_shared<Cell>();
        }
    }
}

int Spreadsheet::getRows() const {
    return rows;
}

void Spreadsheet::setRows(int rows) {
    Spreadsheet::rows = rows;
}

int Spreadsheet::getColumns() const {
    return columns;
}

bool Spreadsheet::hasCellValue(int row, int column) const {
    return matrix[row][column]->hasAssignedValue();
}

void Spreadsheet::setColumns(int columns) {
    Spreadsheet::columns = columns;
}

void Spreadsheet::setCellValue(int row, int column, double value) {
    matrix[row][column]->removeFormula();
    matrix[row][column]->setValue(value);
}

double Spreadsheet::getCellValue(int row, int column) const {
    return matrix[row][column]->getValue();
}

void Spreadsheet::setCellFormula(int row, int column, std::string formula) {
    int parsedRow = 0, parsedColumn = 0;
    std::string fType;
    std::list<std::shared_ptr<Cell>> involvedCells;
    std::list<std::string> parsedFormula = parseFormulaString(formula);
    bool validFormula = true;

    if (!parsedFormula.empty()) {
        fType = std::move(parsedFormula.front());
        parsedFormula.pop_front();
        for (std::string substring : parsedFormula) {
            if (substring.size() == 2) {
                parsedRow = substring[0] - CHAR_TO_NUMBER;
                parsedColumn = substring[1] - CHAR_TO_NUMBER;
                involvedCells.push_back(matrix[parsedRow][parsedColumn]);
                if (parsedRow == row && parsedColumn == column)
                    validFormula = false; //evita il riferimento ciclico
            }
            else
                validFormula = false;
        }
    } else {
        validFormula = false;
    }

    int op;
    if (fType == "sum") {
        op = 0;
    }
    else if (fType == "max") {
        op = 1;
    }
    else if (fType == "min") {
        op = 2;
    }
    else if (fType == "avg") {
        op = 3;
    }
    else {
        validFormula = false;
    }

    if (validFormula)
        matrix[row][column]->setFormula(op, involvedCells, formula);
}

std::string Spreadsheet::getCellFormula(int row, int column) const {
    if (matrix[row][column]->getFormula() != nullptr)
        return matrix[row][column]->getFormula()->getDefinition();
    return "none";
}

std::list<std::string> Spreadsheet::parseFormulaString(std::string& formula) {
    int startIndex = 0, endIndex = 0;
    std::list<std::string> parsedFormula;
    std::string substr;

    for (int i = 0; i < formula.size(); i++) {
        if(formula[i] == EMPTY_SPACE){
            endIndex = i;
            substr.append(formula, startIndex, endIndex - startIndex);
            parsedFormula.push_back(substr);
            startIndex = i + 1;
            substr.clear();
        }
        if (formula[i] == COMMA) {
            endIndex = i;
            substr.append(formula, startIndex, endIndex - startIndex);
            if (!contains(parsedFormula, substr))
                parsedFormula.push_back(substr);
            startIndex = i + 1;
            substr.clear();
        }
        if (i == formula.size() - 1) {
            endIndex = i;
            substr.append(formula, startIndex, endIndex);
            if (!contains(parsedFormula, substr))
                parsedFormula.push_back(substr);
            startIndex = i + 1;
            substr.clear();
        }
    }
    return parsedFormula;
}

bool Spreadsheet::contains(std::list<std::string> list, std::string str) {
    for (std::string el : list) {
        if (el == str)
            return true;
    }
    return false;
}

void Spreadsheet::clearCell(int row, int column){
    matrix[row][column]->removeFormula();
    matrix[row][column]->setValue(0);
    matrix[row][column]->setHasValue(false);
}