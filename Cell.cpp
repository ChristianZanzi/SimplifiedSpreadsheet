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
    notify();
}

double Cell::getValue() {
    return value;
}

void Cell::setFormula(int fType, std::vector<Cell*> &involvedCells) {
    std::vector<double> cellsValues;
    for (auto &involvedCell : involvedCells) {
        involvedCell->subscribe(this);
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

void Cell::subscribe(Observer *o) {
    observers.push_back(o);
}

void Cell::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Cell::notify() {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++) {
        (*itr)->update();
    }
}

void Cell::update() {
    setValue(formula->calculate());
}

void Cell::attach() {

}

void Cell::detach() {

}