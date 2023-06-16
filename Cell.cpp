//
// Created by Christian on 25/05/2023.
//

#include "Cell.h"
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Avg.h"

double Cell::getValue() const {
    return value;
}

void Cell::setValue(const double value) {
    Cell::value = value;
    hasValue = true;
    notify();
}

bool Cell::hasAssignedValue() const {
    return hasValue;
}

void Cell::setHasValue(bool hasValue) {
    Cell::hasValue = hasValue;
    notify();
}

const std::list<std::shared_ptr<Cell>>& Cell::getDependencies() const {
    return dependencies;
}

void Cell::setDependencies(const std::list<std::shared_ptr<Cell>>& dependencies) {
    Cell::dependencies = dependencies;
}

void Cell::setFormula(int fType, std::list<std::shared_ptr<Cell>>& involvedCells, std::string f) {
    removeFormula();
    std::list<double> cellsValues;
    setDependencies(involvedCells);
    for (auto &involvedCell : involvedCells) {
        if (involvedCell->hasAssignedValue())
            cellsValues.push_back(involvedCell->getValue());
        involvedCell->subscribe(this);
    }
    switch(fType) {
        case 0:
            formula = std::make_shared<Sum>();
            formula->setDefinition(f);
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            hasValue = true;
            break;
        case 1:
            formula = std::make_shared<Max>();
            formula->setDefinition(f);
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            hasValue = true;
            break;
        case 2:
            formula = std::make_shared<Min>();
            formula->setDefinition(f);
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            hasValue = true;
            break;
        case 3:
            formula = std::make_shared<Avg>();
            formula->setDefinition(f);
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            hasValue = true;
            break;
        default:

            break;
    }
}

const std::shared_ptr<Formula>& Cell::getFormula() const {
    return formula;
}

void Cell::removeFormula() {
    formula.reset();
    for (const auto &observedCell : dependencies) {
        observedCell->unsubscribe(this);
    }
}

void Cell::subscribe(Observer* o) {
    observers.push_back(o);
}

void Cell::unsubscribe(Observer* o) {
    observers.remove(o);
}

void Cell::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}

void Cell::update() {
    if (formula) {
        std::list<double> values;
        for (const auto &observedCell : getDependencies()) {
            if (observedCell->hasAssignedValue())
                values.push_back(observedCell->getValue());
        }
        formula->setOperands(values);
        setValue(formula->calculate());
    }
}