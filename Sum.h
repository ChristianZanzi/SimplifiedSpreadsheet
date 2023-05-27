//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_SUM_H
#define SIMPLIFIEDSPREADSHEET_SUM_H

#include "Formula.h"
#include "vector"

class Sum : public Formula {
public:
    double calculate() override;

};


#endif //SIMPLIFIEDSPREADSHEET_SUM_H
