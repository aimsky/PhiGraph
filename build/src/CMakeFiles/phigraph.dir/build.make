# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wubo/project/github/PhiGraph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wubo/project/github/PhiGraph/build

# Include any dependencies generated for this target.
include src/CMakeFiles/phigraph.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/phigraph.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/phigraph.dir/flags.make

src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o: src/CMakeFiles/phigraph.dir/flags.make
src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o: ../src/engine/phigraph_init.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/project/github/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o -c /home/wubo/project/github/PhiGraph/src/engine/phigraph_init.cpp

src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.i"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/project/github/PhiGraph/src/engine/phigraph_init.cpp > CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.i

src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.s"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/project/github/PhiGraph/src/engine/phigraph_init.cpp -o CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.s

src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o.requires:

.PHONY : src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o.requires

src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o.provides: src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/phigraph.dir/build.make src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o.provides.build
.PHONY : src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o.provides

src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o.provides.build: src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o


src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o: src/CMakeFiles/phigraph.dir/flags.make
src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o: ../src/engine/phigraph_engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/project/github/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o -c /home/wubo/project/github/PhiGraph/src/engine/phigraph_engine.cpp

src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.i"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/project/github/PhiGraph/src/engine/phigraph_engine.cpp > CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.i

src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.s"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/project/github/PhiGraph/src/engine/phigraph_engine.cpp -o CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.s

src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o.requires:

.PHONY : src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o.requires

src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o.provides: src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/phigraph.dir/build.make src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o.provides.build
.PHONY : src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o.provides

src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o.provides.build: src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o


src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o: src/CMakeFiles/phigraph.dir/flags.make
src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o: ../src/structure/vertexSubset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/project/github/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o -c /home/wubo/project/github/PhiGraph/src/structure/vertexSubset.cpp

src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.i"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/project/github/PhiGraph/src/structure/vertexSubset.cpp > CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.i

src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.s"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/project/github/PhiGraph/src/structure/vertexSubset.cpp -o CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.s

src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o.requires:

.PHONY : src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o.requires

src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o.provides: src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/phigraph.dir/build.make src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o.provides.build
.PHONY : src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o.provides

src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o.provides.build: src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o


src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o: src/CMakeFiles/phigraph.dir/flags.make
src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o: ../src/structure/vertex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/project/github/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phigraph.dir/structure/vertex.cpp.o -c /home/wubo/project/github/PhiGraph/src/structure/vertex.cpp

src/CMakeFiles/phigraph.dir/structure/vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phigraph.dir/structure/vertex.cpp.i"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/project/github/PhiGraph/src/structure/vertex.cpp > CMakeFiles/phigraph.dir/structure/vertex.cpp.i

src/CMakeFiles/phigraph.dir/structure/vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phigraph.dir/structure/vertex.cpp.s"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/project/github/PhiGraph/src/structure/vertex.cpp -o CMakeFiles/phigraph.dir/structure/vertex.cpp.s

src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o.requires:

.PHONY : src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o.requires

src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o.provides: src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/phigraph.dir/build.make src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o.provides.build
.PHONY : src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o.provides

src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o.provides.build: src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o


src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o: src/CMakeFiles/phigraph.dir/flags.make
src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o: ../src/io/graph_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/project/github/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phigraph.dir/io/graph_io.cpp.o -c /home/wubo/project/github/PhiGraph/src/io/graph_io.cpp

src/CMakeFiles/phigraph.dir/io/graph_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phigraph.dir/io/graph_io.cpp.i"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/project/github/PhiGraph/src/io/graph_io.cpp > CMakeFiles/phigraph.dir/io/graph_io.cpp.i

src/CMakeFiles/phigraph.dir/io/graph_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phigraph.dir/io/graph_io.cpp.s"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/project/github/PhiGraph/src/io/graph_io.cpp -o CMakeFiles/phigraph.dir/io/graph_io.cpp.s

src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o.requires:

.PHONY : src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o.requires

src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o.provides: src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/phigraph.dir/build.make src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o.provides.build
.PHONY : src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o.provides

src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o.provides.build: src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o


src/CMakeFiles/phigraph.dir/utils/command.cpp.o: src/CMakeFiles/phigraph.dir/flags.make
src/CMakeFiles/phigraph.dir/utils/command.cpp.o: ../src/utils/command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/project/github/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/phigraph.dir/utils/command.cpp.o"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phigraph.dir/utils/command.cpp.o -c /home/wubo/project/github/PhiGraph/src/utils/command.cpp

src/CMakeFiles/phigraph.dir/utils/command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phigraph.dir/utils/command.cpp.i"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/project/github/PhiGraph/src/utils/command.cpp > CMakeFiles/phigraph.dir/utils/command.cpp.i

src/CMakeFiles/phigraph.dir/utils/command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phigraph.dir/utils/command.cpp.s"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/project/github/PhiGraph/src/utils/command.cpp -o CMakeFiles/phigraph.dir/utils/command.cpp.s

src/CMakeFiles/phigraph.dir/utils/command.cpp.o.requires:

.PHONY : src/CMakeFiles/phigraph.dir/utils/command.cpp.o.requires

src/CMakeFiles/phigraph.dir/utils/command.cpp.o.provides: src/CMakeFiles/phigraph.dir/utils/command.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/phigraph.dir/build.make src/CMakeFiles/phigraph.dir/utils/command.cpp.o.provides.build
.PHONY : src/CMakeFiles/phigraph.dir/utils/command.cpp.o.provides

src/CMakeFiles/phigraph.dir/utils/command.cpp.o.provides.build: src/CMakeFiles/phigraph.dir/utils/command.cpp.o


src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o: src/CMakeFiles/phigraph.dir/flags.make
src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o: ../src/utils/gettime.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/project/github/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phigraph.dir/utils/gettime.cpp.o -c /home/wubo/project/github/PhiGraph/src/utils/gettime.cpp

src/CMakeFiles/phigraph.dir/utils/gettime.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phigraph.dir/utils/gettime.cpp.i"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/project/github/PhiGraph/src/utils/gettime.cpp > CMakeFiles/phigraph.dir/utils/gettime.cpp.i

src/CMakeFiles/phigraph.dir/utils/gettime.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phigraph.dir/utils/gettime.cpp.s"
	cd /home/wubo/project/github/PhiGraph/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/project/github/PhiGraph/src/utils/gettime.cpp -o CMakeFiles/phigraph.dir/utils/gettime.cpp.s

src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o.requires:

.PHONY : src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o.requires

src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o.provides: src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/phigraph.dir/build.make src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o.provides.build
.PHONY : src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o.provides

src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o.provides.build: src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o


# Object files for target phigraph
phigraph_OBJECTS = \
"CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o" \
"CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o" \
"CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o" \
"CMakeFiles/phigraph.dir/structure/vertex.cpp.o" \
"CMakeFiles/phigraph.dir/io/graph_io.cpp.o" \
"CMakeFiles/phigraph.dir/utils/command.cpp.o" \
"CMakeFiles/phigraph.dir/utils/gettime.cpp.o"

# External object files for target phigraph
phigraph_EXTERNAL_OBJECTS =

../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o
../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o
../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o
../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o
../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o
../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/utils/command.cpp.o
../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o
../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/build.make
../lib/libphigraph.a: src/CMakeFiles/phigraph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wubo/project/github/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library ../../lib/libphigraph.a"
	cd /home/wubo/project/github/PhiGraph/build/src && $(CMAKE_COMMAND) -P CMakeFiles/phigraph.dir/cmake_clean_target.cmake
	cd /home/wubo/project/github/PhiGraph/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phigraph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/phigraph.dir/build: ../lib/libphigraph.a

.PHONY : src/CMakeFiles/phigraph.dir/build

src/CMakeFiles/phigraph.dir/requires: src/CMakeFiles/phigraph.dir/engine/phigraph_init.cpp.o.requires
src/CMakeFiles/phigraph.dir/requires: src/CMakeFiles/phigraph.dir/engine/phigraph_engine.cpp.o.requires
src/CMakeFiles/phigraph.dir/requires: src/CMakeFiles/phigraph.dir/structure/vertexSubset.cpp.o.requires
src/CMakeFiles/phigraph.dir/requires: src/CMakeFiles/phigraph.dir/structure/vertex.cpp.o.requires
src/CMakeFiles/phigraph.dir/requires: src/CMakeFiles/phigraph.dir/io/graph_io.cpp.o.requires
src/CMakeFiles/phigraph.dir/requires: src/CMakeFiles/phigraph.dir/utils/command.cpp.o.requires
src/CMakeFiles/phigraph.dir/requires: src/CMakeFiles/phigraph.dir/utils/gettime.cpp.o.requires

.PHONY : src/CMakeFiles/phigraph.dir/requires

src/CMakeFiles/phigraph.dir/clean:
	cd /home/wubo/project/github/PhiGraph/build/src && $(CMAKE_COMMAND) -P CMakeFiles/phigraph.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/phigraph.dir/clean

src/CMakeFiles/phigraph.dir/depend:
	cd /home/wubo/project/github/PhiGraph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wubo/project/github/PhiGraph /home/wubo/project/github/PhiGraph/src /home/wubo/project/github/PhiGraph/build /home/wubo/project/github/PhiGraph/build/src /home/wubo/project/github/PhiGraph/build/src/CMakeFiles/phigraph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/phigraph.dir/depend
