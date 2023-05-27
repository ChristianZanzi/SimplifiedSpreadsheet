//
// Created by Christian on 25/05/2023.
//

#include "Avg.h"

double Avg::calculate(std::vector<double> operands) {
    double result;
    for (int i = 0; i < operands.size(); i++) {
            result += operands[i];
    }
    return result/operands.size();
}