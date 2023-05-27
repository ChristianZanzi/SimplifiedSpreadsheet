//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_CELL_H
#define SIMPLIFIEDSPREADSHEET_CELL_H

#include "Formula.h"
#include <string>
#include <vector>

class Cell {
public:
    Cell();
    void setValue(double v);
    double getValue();
    void setFormula(int fType, std::vector<Cell*> &involvedCells);

private:
    double value;
    Formula* formula;
};


#endif //SIMPLIFIEDSPREADSHEET_CELL_H
