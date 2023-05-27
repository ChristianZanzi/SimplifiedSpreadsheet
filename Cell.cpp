//
// Created by Christian on 25/05/2023.
//

#include "Cell.h"

void Cell::setValue(double v) {
    value = v;
}

double Cell::getValue() {
    return value;
}

void Cell::setFormula(Formula *formula) {
    this->formula = formula;
}
