//
// Created by Christian on 25/05/2023.
//

#include "Spreadsheet.h"
#include <iostream>

Spreadsheet::Spreadsheet(int numRows, int numColumns): rows(numRows), columns(numColumns) {
    matrix = std::make_unique<std::unique_ptr<Cell[]>[]>(rows);
    for(int i = 0; i < rows; i++){
        matrix[i] = std::make_unique<Cell[]>(columns);
    }
    /*matrix = new Cell*[rows];
    for (int i=0; i < rows; i++) {
        matrix[i] = new Cell[columns];
    }*/
}

/*Spreadsheet::~Spreadsheet(){
    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
} */

void Spreadsheet::setCellValue(int row, int column, double value) {
    matrix[row][column].setValue(value);
}

double Spreadsheet::getCellValue(int row, int column) const {
    return matrix[row][column].getValue();
}

void Spreadsheet::setCellFormula(int row, int column, std::string formula) {
    int startIndex = 0, endIndex = 0;
    std::string fType;
    //std::vector<Cell*> involvedCells;
    std::list<std::shared_ptr<Cell>> involvedCells;
    for (int i = 0; i < formula.size(); i++){
        //std::cout << "passo di lettura:" << formula[i] << std::endl;
        if(formula[i] == ' '){
            //TODO controlla che il tipo di funzione sia corretto
            endIndex = i;
            fType.append(formula, startIndex, endIndex - startIndex);
            startIndex = i + 1;
        }
        if(formula[i] == ','){
            //TODO controlla che l'identificativo della cella sia corretto
            endIndex = i - 1;
            int r = formula[startIndex] - '0';
            int c = formula[endIndex] - '0';
            //involvedCells.push_back(std::make_shared<Cell>(matrix[r][c]));
            //involvedCells.push_back(&matrix[r][c]); //nella lista viene immesso il riferimento alla cella
            involvedCells.push_back(std::shared_ptr<Cell>(&matrix[r][c], [](Cell*) {}));
            //Nel metodo Spreadsheet::setCellFormula, stai creando una copia della cella matrix[r][c]
            // utilizzando std::make_shared<Cell>(matrix[r][c]). Tuttavia, questo creerà un nuovo oggetto Cell
            // con una copia dei valori, ma non manterrà il legame con la cella originale nella matrice.
            // Per mantenere il riferimento corretto alla cella originale, puoi passare direttamente un puntatore condiviso
            // alla cella matrix[r][c] alla lista involvedCells
            startIndex = i + 1;
        }
        if(i == formula.size() - 1){
            endIndex = i;
            int r = formula[startIndex] - '0';
            int c = formula[endIndex] - '0';
            //involvedCells.push_back(&matrix[r][c]);
            //involvedCells.push_back(std::make_shared<Cell>(matrix[r][c]));
            involvedCells.push_back(std::shared_ptr<Cell>(&matrix[r][c], [](Cell*) {}));
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
        op = 2;
    }
    else if (fType == "avg"){
        op = 3;
    }
    else{
        std::cout << "errore, tipo della formula sbagliato";
    }
    matrix[row][column].setFormula(op, involvedCells, formula);
}

std::string Spreadsheet::getCellFormula(int row, int column) const {
    if(matrix[row][column].getFormula() != nullptr)
        return matrix[row][column].getFormula()->getDefinition();
    return "none";
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

void Spreadsheet::setColumns(int columns) {
    Spreadsheet::columns = columns;
}
