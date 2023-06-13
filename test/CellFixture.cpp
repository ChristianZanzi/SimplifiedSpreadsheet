//
// Created by Christian on 11/06/2023.
//

#include "gtest/gtest.h"
#include "../Cell.h"
#include <memory>

class CellSuite : public ::testing::Test {
protected:
    void SetUp() override {
        cell = std::make_shared<Cell>();
    }

    void TearDown() override {
        cell.reset();
    }

    std::shared_ptr<Cell> cell;
    std::list<std::shared_ptr<Cell>> dependencies;
};

TEST_F(CellSuite, NotifyTest) {
    std::shared_ptr<Cell> observed1 = std::make_shared<Cell>();
    std::shared_ptr<Cell> observed2 = std::make_shared<Cell>();
    observed1->setValue(10);
    observed2->setValue(20);
    dependencies.push_back(observed1);
    dependencies.push_back(observed2);
    const std::string formulaDefinition = "sum 00,01";
    cell->setFormula(0, dependencies, formulaDefinition);
    ASSERT_EQ(30, cell->getValue());
    observed1->setValue(6);
    observed2->setValue(5);
    ASSERT_EQ(11, cell->getValue());
    dependencies.clear();
}

TEST_F(CellSuite, UpdateTest) {
    std::shared_ptr<Cell> observed3 = std::make_shared<Cell>();
    std::shared_ptr<Cell> observed4 = std::make_shared<Cell>();
    observed3->setValue(2);
    dependencies.push_back(observed3);
    dependencies.push_back(observed4);
    const std::string formulaDefinition = "avg 00,01";
    cell->setFormula(3, dependencies, formulaDefinition);
    ASSERT_EQ(2, observed3->getValue());
    ASSERT_EQ(0, observed4->getValue());
    ASSERT_EQ(2, cell->getValue());
    dependencies.clear();
}