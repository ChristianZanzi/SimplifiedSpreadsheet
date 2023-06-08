//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_MAX_H
#define SIMPLIFIEDSPREADSHEET_MAX_H


#include "Formula.h"

class Max: public Formula {
public:
    double calculate() override;
};


#endif //SIMPLIFIEDSPREADSHEET_MAX_H
