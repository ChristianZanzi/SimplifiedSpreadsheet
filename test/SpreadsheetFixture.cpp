//
// Created by Christian on 09/06/2023.
//

#include "gtest/gtest.h"
#include "../Spreadsheet.h"
#include <mutex>
#include <condition_variable>


class SpreadsheetSuite : public ::testing::Test {
protected:
    virtual void SetUp() {
        s = new Spreadsheet(5, 5);
    }

    void TearDown() {
        delete s;
    }

    Spreadsheet *s;
};

TEST_F(SpreadsheetSuite, TestInit) {
    ASSERT_EQ(5, s->getColumns());
    ASSERT_EQ(5, s->getRows());
}

TEST_F(SpreadsheetSuite, TestValuesInput) {
    s->setCellValue(0, 0, 1000);
    ASSERT_EQ(1000, s->getCellValue(0, 0));

    s->setCellValue(0, 0, 1);
    ASSERT_EQ(1, s->getCellValue(0, 0));

    s->setCellValue(1, 1, 10000000000000000);
    ASSERT_EQ(0, s->getCellValue(1, 1));
}

TEST_F(SpreadsheetSuite, TestFormulasInput) {
    s->setCellFormula(1, 1, "sum 00,01,02");
    ASSERT_EQ("sum 00,01,02", s->getCellFormula(1, 1));

    s->setCellFormula(1, 1, "avr 00,01");  //errore nella scrittura dell'operazione
    ASSERT_EQ("none", s->getCellFormula(1, 1));

    s->setCellFormula(1, 0, "avg 000,01");  //errore nella scrittura deglio operatori
    ASSERT_EQ("none", s->getCellFormula(1, 0));

    s->setCellFormula(2, 2, "max 00,22");  //referenza ciclica
    ASSERT_EQ("none", s->getCellFormula(2, 2));
}
