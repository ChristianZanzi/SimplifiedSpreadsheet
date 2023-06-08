//
// Created by Christian on 25/05/2023.
//

#include "Formula.h"

const std::list<double>& Formula::getOperands() const {
    return operands;
}

void Formula::setOperands(const std::list<double> &operands) {
    this->operands = operands;
}

const std::string &Formula::getDefinition() const {
    return definition;
}

void Formula::setDefinition(const std::string &definition) {
    Formula::definition = definition;
}

