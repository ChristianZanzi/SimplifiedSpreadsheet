//
// Created by Christian on 25/05/2023.
//

#ifndef SIMPLIFIEDSPREADSHEET_OBSERVER_H
#define SIMPLIFIEDSPREADSHEET_OBSERVER_H


class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

#endif //SIMPLIFIEDSPREADSHEET_OBSERVER_H
