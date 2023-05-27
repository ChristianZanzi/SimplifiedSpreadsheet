//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_SPREADSHEET_H
#define SIMPLIFIEDSPREADSHEET_SPREADSHEET_H

#include "Subject.h"
#include "Observer.h"
#include "Cell.h"
#include <list>
#include <string>

class Spreadsheet : public Subject{
public:
    Spreadsheet(int numRows, int numColumns);

    ~Spreadsheet() override;

    void setCellValue(int row, int column, double value);
    double getCellValue(int row, int column) const;
    void setCellFormula(int row, int column, std::string& formula);

    void subscribe(Observer* o) override;

    void unsubscribe(Observer* o) override;
    void notify() override;

private:
    int rows;
    int columns;
    Cell** matrix;
    std::list<Observer*> observers;



};


#endif //SIMPLIFIEDSPREADSHEET_SPREADSHEET_H
