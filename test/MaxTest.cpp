//
// Created by chri on 13/06/23.
//

#include "gtest/gtest.h"
#include "../Max.h"

TEST(Spreadsheet, TestMax) {
    Max* m = new Max();
    std::list<double> values;
    values.push_back(0);
    values.push_back(-10);
    values.push_back(-15.45);
    values.push_back(-20);
    m->setOperands(values);
    double result = m->calculate();
    ASSERT_EQ(0, result);
}