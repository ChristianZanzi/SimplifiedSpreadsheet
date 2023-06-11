//
// Created by Christian on 25/05/2023.
//

#include "Sum.h"

double Sum::calculate() {
    double result = 0;
    for (auto operand : getOperands()) {
        result += operand;
    }
    return result;
}