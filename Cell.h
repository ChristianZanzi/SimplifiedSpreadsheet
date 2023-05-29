//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_CELL_H
#define SIMPLIFIEDSPREADSHEET_CELL_H

#include "Formula.h"
#include "Observer.h"
#include "Subject.h"
#include <string>
#include <vector>
#include <list>

class Cell : public Subject, public Observer {
public:
    Cell();
    void setValue(double v);
    double getValue();
    void setFormula(int fType, std::vector<Cell*> &involvedCells);

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;

    void update();
    void attach();
    void detach();

private:
    double value;
    Formula* formula;
    std::list<Observer*> observers;
};


#endif //SIMPLIFIEDSPREADSHEET_CELL_H
