//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_AVG_H
#define SIMPLIFIEDSPREADSHEET_AVG_H


#include "Formula.h"

class Avg: public Formula{
public:
    double calculate() override;
};


#endif //SIMPLIFIEDSPREADSHEET_AVG_H
