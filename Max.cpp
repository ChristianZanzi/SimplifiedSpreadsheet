//
// Created by Christian on 25/05/2023.
//

#include "Max.h"

double Max::calculate() {
    if (getOperands().empty())
        return 0;
    double result = getOperands().front();
    for (double operand : getOperands()) {
        if (result < operand)
            result = operand;
    }
    return result;
}