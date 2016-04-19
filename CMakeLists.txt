cmake_minimum_required(VERSION 3.5)

#project name

PROJECT(PhiGraph)
SET(CMAKE_C_COMPILER "g++")

#ADD_SUBDIRECTOR(src bin)


SET(CMAKE_INSTALL_PREFIX /usr/local)
#SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})


#head file path

INCLUDE_DIRECTORIES(

src

)


#source directory

AUX_SOURCE_DIRECTORY(apps DIR_SRCS)

#set environment variable

SET(SRC_LIST ${DIR_SRCS})



#add executable file

ADD_EXECUTABLE(phigraph ${SRC_LIST})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)




#set extern libraries

#SET(LIBRARIES

#libm.so

#)

#add link library

#TARGET_LINK_LIBRARIES(phigraph ${LIBRARIES})
