//
// Created by Christian on 09/06/2023.
//

#include "gtest/gtest.h"
#include <mutex>
#include <condition_variable>


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}