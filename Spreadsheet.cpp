//
// Created by Christian on 25/05/2023.
//

#include "Spreadsheet.h"
#include "Cell.h"

Spreadsheet::Spreadsheet(int numRows, int numColumns): rows(numRows), columns(numColumns) {
    matrix = new Cell*[rows];
    for (int i=0; i < rows; i++) {
        matrix[i] = new Cell[columns];
    }
}

Spreadsheet::~Spreadsheet(){
    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Spreadsheet::setCellValue(int row, int column, double value) {
    matrix[row][column].setValue(value);
}

double Spreadsheet::getCellValue(int row, int column) const {
    return matrix[row][column].getValue();
}

void Spreadsheet::setCellFormula(int row, int column, std::string &formula) {
    matrix[row][column].setFormula()
}