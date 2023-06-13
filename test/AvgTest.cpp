//
// Created by chri on 13/06/23.
//

#include "gtest/gtest.h"
#include "../Avg.h"

TEST(Spreadsheet, TestAvg) {
    Avg* a = new Avg();
    std::list<double> values;
    values.push_back(0);
    values.push_back(-10);
    values.push_back(15.45);
    values.push_back(20);
    a->setOperands(values);
    double result = a->calculate();
    ASSERT_EQ(6.3625, result);
}

TEST(Spreadsheet, TestAvgNoValues) {
    Avg* a = new Avg();
    std::list<double> values;
    a->setOperands(values);
    double result = a->calculate();
    ASSERT_EQ(0, result);
}