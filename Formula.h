//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_FORMULA_H
#define SIMPLIFIEDSPREADSHEET_FORMULA_H

#include <list>
#include <string>

class Formula {
public:
    virtual ~Formula() = default;

    const std::list<double>& getOperands() const;
    void setOperands(const std::list<double>& operands);

    const std::string &getDefinition() const;
    void setDefinition(const std::string &definition);

    virtual double calculate() = 0;

private:
    std::string definition;
    std::list<double> operands;
};

#endif //SIMPLIFIEDSPREADSHEET_FORMULA_H
