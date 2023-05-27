//
// Created by Christian on 25/05/2023.
//

#include <iostream>
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
    int startIndex = 0, endIndex = 0;
    std::string fType;
    std::vector<Cell*> involvedCells;
    for (int i = 0; i < formula.size(); i++){
        if(formula[i] == ' '){
            //TODO controlla che il tipo di funzione sia corretto
            endIndex = i - 1;
            fType.append(formula, startIndex, endIndex - startIndex);
            startIndex = i + 1;
        }
        if(formula[i] == ','){
            //TODO controlla che l'identificativo della cella sia corretto
            endIndex = i - 1;
            row = (int)formula[startIndex];
            column = (int)formula[endIndex];
            involvedCells.push_back(&matrix[row][column]); //nella lista viene immesso il riferimento alla cella
            startIndex = i + 1;
        }
    }
    int op;
    if (fType == "sum"){
        op = 0;
    }
    else if (fType == "max"){
        op = 1;
    }
    else if (fType == "min"){
        op = 3;
    }
    else if (fType == "avg"){
        op = 4;
    }
    else{
        std::cout << "errore, tipo della formula sbagliato";
    }
    matrix[row][column].setFormula(op, involvedCells);
    //TODO rilasciare la memoria occuopata dalla lista
}