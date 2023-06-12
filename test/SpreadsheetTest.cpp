//
// Created by Christian on 09/06/2023.
//
#include "gtest/gtest.h"
#include "../Spreadsheet.h"

TEST(Spreadsheet, TestParseFormula) {
    Spreadsheet s(3, 3);

    std::string formula = "sum 00,00,01";
    std::list<std::string> parsedFormula = s.parseFormulaString(formula);
    ASSERT_EQ("sum", parsedFormula.front());
    parsedFormula.pop_front();
    ASSERT_EQ("00", parsedFormula.front());
    parsedFormula.pop_front();
    ASSERT_EQ("01", parsedFormula.front());
}