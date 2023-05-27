//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_FORMULA_H
#define SIMPLIFIEDSPREADSHEET_FORMULA_H

#include <list>

class Formula {
public:
    Formula();
    virtual ~Formula() = default;

    virtual double calculate(std::list<double> operands) = 0;

    const std::list<double> &getOperands() const;

    void setOperands(const std::list<double> &operands);

    double getResult() const;

    //TODO: creare i metodi per aggiungere operandi alla lista
    //TODO: il costruttore dovrebbe ricevere una stringa contenente dei caratteri e dovrebbe essere in grado di creare una lista di operandi da esssa
private:
    std::list<double> operands;
    double result;
};


#endif //SIMPLIFIEDSPREADSHEET_FORMULA_H
