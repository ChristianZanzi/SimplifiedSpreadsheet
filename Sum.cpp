//
// Created by Christian on 25/05/2023.
//

#include "Sum.h"


double Sum::calculate(std::vector<double> operands) {
    double result = 0;
    for (double operand : operands) {
        result += operand;
    }
    return result;
}