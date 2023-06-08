//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_MIIN_H
#define SIMPLIFIEDSPREADSHEET_MIIN_H


#include "Formula.h"

class Min: public Formula {
public:
    double calculate() override;
};


#endif //SIMPLIFIEDSPREADSHEET_MIIN_H
