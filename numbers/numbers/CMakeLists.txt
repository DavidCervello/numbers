cmake_minimum_required (VERSION 3.2)

project (numbers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(numbers main.cpp src/Sources/TextParser/TextParser.cpp src/Sources/NumberChecker/NumberChecker.cpp)
