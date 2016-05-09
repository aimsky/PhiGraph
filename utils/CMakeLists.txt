cmake_minimum_required(VERSION 3.5)
project (PhiGraph)
SET(CMAKE_C_COMPILER "g++")

SET(SRC_LIST GraphGenerator.cpp)

ADD_EXECUTABLE(generator ${SRC_LIST})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
