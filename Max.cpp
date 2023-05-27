//
// Created by Christian on 25/05/2023.
//

#include "Max.h"

double Max::calculate() {
    double result;
    for (double operand : getOperands()) {
        if (result < operand)
            result = operand;
    }
    return result;
}