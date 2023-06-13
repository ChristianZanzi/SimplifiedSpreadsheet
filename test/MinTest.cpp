//
// Created by chri on 13/06/23.
//

#include "gtest/gtest.h"
#include "../Min.h"

TEST(Spreadsheet, TestMin) {
    Min* m = new Min();
    std::list<double> values;
    values.push_back(0);
    values.push_back(-10);
    values.push_back(15);
    values.push_back(20);
    m->setOperands(values);
    double result = m->calculate();
    ASSERT_EQ(-10, result);
}