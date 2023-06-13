//
// Created by chri on 13/06/23.
//

#include "gtest/gtest.h"
#include "../Sum.h"

TEST(Spreadsheet, TestSum) {
    Sum* s = new Sum();
    std::list<double> values;
    values.push_back(0);
    values.push_back(-10);
    values.push_back(15.45);
    values.push_back(20);
    s->setOperands(values);
    double result = s->calculate();
    ASSERT_EQ(25.45, result);
}