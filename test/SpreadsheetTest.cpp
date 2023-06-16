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

TEST(Spreadsheet, TestHasCircularReference) {
    Spreadsheet s(3, 3);

    s.setCellFormula(0, 1, "sum 00,02");
    ASSERT_EQ("sum 00,02", s.getCellFormula(0, 1));

    s.setCellFormula(0, 2, "sum 00,01");
    ASSERT_EQ("none", s.getCellFormula(0, 2));
}

TEST(SpreadsheetTest, OutOfBoundsException) {
    Spreadsheet s(3, 3);

    EXPECT_THROW(s.hasCellValue(10, 5), std::out_of_range);
    EXPECT_THROW(s.hasCellValue(-1, 2), std::out_of_range);;

    EXPECT_THROW(s.setCellValue(8, 4, 10), std::out_of_range);
    EXPECT_THROW(s.setCellValue(2, -1, 5), std::out_of_range);

    EXPECT_THROW(s.getCellValue(7, 3), std::out_of_range);
    EXPECT_THROW(s.getCellValue(-2, 6), std::out_of_range);

    EXPECT_THROW(s.setCellFormula(9, 15, "sum 00,01"), std::out_of_range);

    EXPECT_THROW(s.getCellFormula(9, 15), std::out_of_range);
}