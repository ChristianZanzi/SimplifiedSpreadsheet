//
// Created by Christian on 25/05/2023.
//

#include "Formula.h"


const std::vector<double> &Formula::getOperands() const {
    return operands;
}

void Formula::setOperands(const std::vector<double> &operands) {
    this->operands = operands;
}

