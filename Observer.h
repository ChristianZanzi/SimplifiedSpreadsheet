//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_OBSERVER_H
#define SIMPLIFIEDSPREADSHEET_OBSERVER_H


class Observer {
public:
    virtual ~Observer();
    virtual void update(double value) = 0;
    virtual void attach() = 0;
    virtual void detach() = 0;
};

Observer::~Observer() = default;


#endif //SIMPLIFIEDSPREADSHEET_OBSERVER_H
