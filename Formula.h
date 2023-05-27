//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_FORMULA_H
#define SIMPLIFIEDSPREADSHEET_FORMULA_H

#include <vector>

class Formula {
public:
    Formula();
    virtual ~Formula() = default;

    virtual double calculate() = 0;

    const std::vector<double> &getOperands() const;

    void setOperands(const std::vector<double> &operands);


    //TODO: creare i metodi per aggiungere operandi alla lista
    //TODO: il costruttore dovrebbe ricevere una stringa contenente dei caratteri e dovrebbe essere in grado di creare una lista di operandi da esssa
private:
    std::vector<double> operands;
};


#endif //SIMPLIFIEDSPREADSHEET_FORMULA_H
