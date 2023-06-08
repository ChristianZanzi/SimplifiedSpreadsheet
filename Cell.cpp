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

const double Cell::getValue() const {
    return this->value;
}

void Cell::setValue(const double value) {
    this->value = value;
    //if(formula)
     //   formula->setDefinition(" ");
    notify();
}

const std::list<std::shared_ptr<Cell>>& Cell::getDependencies() const {
    return dependencies;
}

void Cell::setDependencies(const std::list<std::shared_ptr<Cell>>& dependencies) {
    this->dependencies = dependencies;
}

void Cell::setFormula(int fType, std::list<std::shared_ptr<Cell>>& involvedCells, std::string f) {
    std::list<double> cellsValues;
    setDependencies(involvedCells);
    for (auto &involvedCell : involvedCells) {
        cellsValues.push_back(involvedCell->getValue());
        involvedCell->subscribe(this);
    }
    switch(fType){
        case 0:
            formula = std::make_shared<Sum>();
            formula->setDefinition(f);
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            break;
        case 1:
            formula = std::make_shared<Max>();
            formula->setDefinition(f);
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            break;
        case 2:
            formula = std::make_shared<Min>();
            formula->setDefinition(f);
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            break;
        case 3:
            formula = std::make_shared<Avg>();
            formula->setDefinition(f);
            formula->setOperands(cellsValues);
            setValue(formula->calculate());
            break;
        default:
            std::cout << "errore";
            break;
    }
}

const std::shared_ptr<Formula>& Cell::getFormula() const{
    return formula;
}

void Cell::subscribe(Observer* o) {
    observers.push_back(o);
}

void Cell::unsubscribe(Observer* o) {
    observers.remove(o);
}

void Cell::notify() {
    for (auto observer : observers) {
        std::cout << "valore aggiornato " << value << std::endl;
        observer->update();
    }
}

void Cell::update() {
    //setFormula(formula->getOperationType(), formula->getOperands()); // TODO capire come passare di nuovo il codice dell'operazione
    //setValue(getValue());
    if(formula) {
        std::list<double> values;
        for(auto dependency : getDependencies()){
            std::cout << "valore usato per aggiornare " << dependency->getValue() << std::endl;
            values.push_back(dependency->getValue());
        }
        formula->setOperands(values);
        setValue(formula->calculate());
    }
}
