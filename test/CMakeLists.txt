add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR ./lib/googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(TEST_SOURCE_FILES runAllTests.cpp SpreadsheetFixture.cpp SpreadsheetTest.cpp CellTest.cpp CellFixture.cpp SumTest.cpp MaxTest.cpp MinTest.cpp AvgTest.cpp)
add_executable(runSimplifiedSpreadsheetTests ${TEST_SOURCE_FILES})
target_link_libraries(runSimplifiedSpreadsheetTests gtest gtest_main core)