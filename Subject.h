//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_SUBJECT_H
#define SIMPLIFIEDSPREADSHEET_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify() = 0;

    virtual ~Subject() = default;
};
#endif //SIMPLIFIEDSPREADSHEET_SUBJECT_H
