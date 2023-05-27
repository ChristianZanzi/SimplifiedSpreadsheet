cmake_minimum_required(VERSION 3.13)
project(SimplifiedSpreadsheet)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimplifiedSpreadsheet main.cpp Spreadsheet.cpp Spreadsheet.h Cell.cpp Cell.h Formula.cpp Formula.h Observer.h Min.cpp Min.h Max.cpp Max.h Avg.cpp Avg.h Sum.cpp Sum.h Subject.h)