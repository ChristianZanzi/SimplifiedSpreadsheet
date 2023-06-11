cmake_minimum_required(VERSION 3.13)
project(SimplifiedSpreadsheet)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)
set(SOURCE_FILES Spreadsheet.cpp Spreadsheet.h Cell.cpp Cell.h Formula.cpp Formula.h Sum.cpp Sum.h Max.cpp Max.h Min.cpp Min.h Avg.cpp Avg.h)

#find_package(Curses REQUIRED)
#include_directories(${CURSES_INCLUDE_DIR})
add_executable(SimplifiedSpreadsheet main.cpp Spreadsheet.cpp Spreadsheet.h Cell.cpp Cell.h Formula.cpp Formula.h Observer.h Min.cpp Min.h Max.cpp Max.h Avg.cpp Avg.h Sum.cpp Sum.h Subject.h)
#target_link_libraries(SimplifiedSpreadsheet  ${CURSES_LIBRARIES})

add_library(core ${SOURCE_FILES})
target_link_libraries(SimplifiedSpreadsheet core)

