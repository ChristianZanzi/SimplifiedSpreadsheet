//
// Created by Christian on 11/06/2023.
//

#include "gtest/gtest.h"
#include "../Cell.h"
#include <memory>


TEST(Cell, SetValueTest) {
    const double value = 10;
    std::shared_ptr<Cell> cell = std::make_shared<Cell>();
    cell->setValue(value);
    ASSERT_EQ(cell->getValue(), value);
}

TEST(Cell, SetFormulaSumTest) {
    std::shared_ptr<Cell> cell = std::make_shared<Cell>();
    std::list<std::shared_ptr<Cell>> dependencies;
    dependencies.push_back(std::make_shared<Cell>());
    dependencies.push_back(std::make_shared<Cell>());
    const std::string formulaDefinition = "sum 00,01";
    cell->setFormula(0, dependencies, formulaDefinition);
    EXPECT_TRUE(cell->getFormula() != nullptr);
    ASSERT_EQ(cell->getValue(), 0);
}

TEST(Cell, SetFormulaAvgTest) {
    std::shared_ptr<Cell> cell = std::make_shared<Cell>();
    std::list<std::shared_ptr<Cell>> dependencies;
    std::shared_ptr<Cell> dep1 = std::make_shared<Cell>();
    dep1->setValue(1);
    std::shared_ptr<Cell> dep2 = std::make_shared<Cell>();
    dep2->setValue(1);
    dependencies.push_back(dep1);
    dependencies.push_back(dep2);
    const std::string formulaDefinition = "avg 00,01";
    cell->setFormula(3, dependencies, formulaDefinition);
    EXPECT_TRUE(cell->getFormula() != nullptr);
    EXPECT_EQ(cell->getValue(), 1);
}
