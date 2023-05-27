//
// Created by Christian on 25/05/2023.
//

#include "Cell.h"
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Avg.h"
#include <vector>
#include <iostream>

void Cell::setValue(double v) {
    value = v;
}

double Cell::getValue() {
    return value;
}

void Cell::setFormula(int fType, std::vector<Cell*> &involvedCells) {
    std::vector<double> cellsValues;
    for (auto &involvedCell : involvedCells) {
        cellsValues.push_back(involvedCell->getValue());
    }
    switch(fType){
        case 0:
            formula = new Sum();
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            break;
        case 1:
            formula = new Max();
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            break;
        case 2:
            formula = new Min();
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            break;
        case 3:
            formula = new Avg();
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            break;
        default:
            std::cout << "errore";
            break;
    }
}
