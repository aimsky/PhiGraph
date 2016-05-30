# Install script for directory: /home/wubo/project/github/PhiGraph/phigraph

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
    "/home/wubo/project/github/PhiGraph/phigraph/api/phigraph_program.h"
    "/home/wubo/project/github/PhiGraph/phigraph/api/phigraph_aligned.h"
    "/home/wubo/project/github/PhiGraph/phigraph/api/parallel.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/engine" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/phigraph/engine/phigraph_init.h"
    "/home/wubo/project/github/PhiGraph/phigraph/engine/phigraph_engine.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/io" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/phigraph/io/seq.h"
    "/home/wubo/project/github/PhiGraph/phigraph/io/graph_io.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/structure" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/phigraph/structure/vertexSubset.h"
    "/home/wubo/project/github/PhiGraph/phigraph/structure/phivector.h"
    "/home/wubo/project/github/PhiGraph/phigraph/structure/graph.h"
    "/home/wubo/project/github/PhiGraph/phigraph/structure/vertex.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph/utils" TYPE FILE FILES
    "/home/wubo/project/github/PhiGraph/phigraph/utils/utils.h"
    "/home/wubo/project/github/PhiGraph/phigraph/utils/command.h"
    "/home/wubo/project/github/PhiGraph/phigraph/utils/parallel.h"
    "/home/wubo/project/github/PhiGraph/phigraph/utils/gettime.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/phigraph" TYPE FILE FILES "/home/wubo/project/github/PhiGraph/phigraph/phigraph.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/wubo/project/github/PhiGraph/lib/libphigraph.a")
endif()

