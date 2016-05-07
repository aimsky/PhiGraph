cmake_minimum_required(VERSION 3.5)

#project name

PROJECT(PhiGraph)
SET(CMAKE_C_COMPILER "g++")

#ADD_SUBDIRECTOR(src bin)


SET(CMAKE_INSTALL_PREFIX /usr/local)

#SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

#head file path

INCLUDE_DIRECTORIES(src)

#source directory

AUX_SOURCE_DIRECTORY(apps DIR_SRCS)

#set environment variable

SET(SRC_LIST ${DIR_SRCS})

#add executable file

ADD_EXECUTABLE(BFS apps/BFS.cpp)
ADD_EXECUTABLE(sssp apps/SSSP.cpp)
ADD_EXECUTABLE(pagerank apps/PageRank.cpp)
ADD_EXECUTABLE(components apps/Components.cpp)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#set extern libraries

#SET(LIBRARIES

#libm.so

#)

#add link library

#TARGET_LINK_LIBRARIES(phigraph ${LIBRARIES})

FIND_PACKAGE( OpenMP REQUIRED)
if(OPENMP_FOUND)
message("OPENMP FOUND")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()
