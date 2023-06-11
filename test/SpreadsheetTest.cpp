//
// Created by Christian on 09/06/2023.
//
#include "gtest/gtest.h"
#include "../Spreadsheet.h"
#include <mutex>
#include <condition_variable>


TEST(Spreadsheet, TestParseFormula) {
    Spreadsheet s(3, 3);

    std::string formula = "sum 00,00,01";
    std::list<std::string> parsedFormula = s.parseFormulaString(formula);
    ASSERT_EQ("sum", parsedFormula.front());
    ASSERT_EQ("00", parsedFormula.front());
    ASSERT_EQ("01", parsedFormula.front());
}