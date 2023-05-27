//
// Created by Christian on 25/05/2023.
//

#include "Min.h"

double Min::calculate() {
    double result;
    for (double operand : getOperands()) {
        if (result > operand)
            result = operand;
    }
    return result;
}