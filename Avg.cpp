//
// Created by Christian on 25/05/2023.
//

#include "Avg.h"

double Avg::calculate() {
    double result;
    for (double operand : getOperands()) {
            result += operand;
    }
    return result/getOperands().size();
}