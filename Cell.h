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
#include <memory>

class Cell : public Subject, public Observer {
public:
    ~Cell() override = default;

    void setValue(double value);
    const double getValue() const;
    bool hasAssignedValue() const;

    const std::list<std::shared_ptr<Cell>>& getDependencies() const;
    void setDependencies(const std::list<std::shared_ptr<Cell>>& dependencies);

    void setFormula(int fType, std::list<std::shared_ptr<Cell>>& involvedCells, std::string f);
    const std::shared_ptr<Formula>& getFormula() const;
    void removeFormula();

    void subscribe(Observer* o) override;
    void unsubscribe(Observer* o) override;
    void notify() override;
    void update() override;

private:
    double value;
    bool hasValue;
    std::shared_ptr<Formula> formula;
    std::list<std::shared_ptr<Cell>> dependencies;
    std::list<Observer*> observers;
};


#endif //SIMPLIFIEDSPREADSHEET_CELL_H
