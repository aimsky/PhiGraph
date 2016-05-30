# Install script for directory: /home/wubo/project/github/PhiGraph/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/api" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/src/api/phigraph_program.h"
    "/home/wubo/project/github/PhiGraph/src/api/phigraph_aligned.h"
    "/home/wubo/project/github/PhiGraph/src/api/parallel.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/engine" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/src/engine/phigraph_init.h"
    "/home/wubo/project/github/PhiGraph/src/engine/phigraph_engine.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/io" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/src/io/seq.h"
    "/home/wubo/project/github/PhiGraph/src/io/graph_io.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/structure" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/src/structure/vertexSubset.h"
    "/home/wubo/project/github/PhiGraph/src/structure/phivector.h"
    "/home/wubo/project/github/PhiGraph/src/structure/graph.h"
    "/home/wubo/project/github/PhiGraph/src/structure/vertex.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/utils" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/src/utils/utils.h"
    "/home/wubo/project/github/PhiGraph/src/utils/command.h"
    "/home/wubo/project/github/PhiGraph/src/utils/parallel.h"
    "/home/wubo/project/github/PhiGraph/src/utils/gettime.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph" TYPE FILE FILES "/home/wubo/project/github/PhiGraph/src/phigraph.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/wubo/project/github/PhiGraph/lib/libphigraph.a")
endif()

