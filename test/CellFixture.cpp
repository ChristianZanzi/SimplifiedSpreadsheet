//
// Created by Christian on 11/06/2023.
//

#include "gtest/gtest.h"
#include "../Cell.h"
#include <memory>

// Test fixture for Cell class
class CellSuite : public ::testing::Test {
protected:
    void SetUp() override {
        cell = std::make_shared<Cell>();
    }

    void TearDown() override {
        cell.reset();
    }

    std::shared_ptr<Cell> cell;
};

TEST_F(CellSuite, NotifyWithFormulaTest) {
    std::shared_ptr<Cell> observed1 = std::make_shared<Cell>();
    std::shared_ptr<Cell> observed2 = std::make_shared<Cell>();
    std::list<std::shared_ptr<Cell>> dependencies;
    dependencies.push_back(observed1);
    dependencies.push_back(observed2);
    const std::string formulaDefinition = "sum 00,01";
    cell->setFormula(0, dependencies, formulaDefinition);
    observed1->setValue(10);
    observed2->setValue(20);

}