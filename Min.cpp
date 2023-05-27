//
// Created by Christian on 25/05/2023.
//

#include "Min.h"

double Min::calculate(std::vector<double> operands) {
    double result;
    for (int i = 0; i < operands.size(); i++) {
        if (result > operands[i])
            result = operands[i];
    }
    return result;
}