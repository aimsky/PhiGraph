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
CMAKE_SOURCE_DIR = /home/wubo/work/project/PhiGraph

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wubo/work/project/PhiGraph/build

# Include any dependencies generated for this target.
include CMakeFiles/phigraph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/phigraph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/phigraph.dir/flags.make

CMakeFiles/phigraph.dir/src/main.cpp.o: CMakeFiles/phigraph.dir/flags.make
CMakeFiles/phigraph.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/work/project/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/phigraph.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/phigraph.dir/src/main.cpp.o -c /home/wubo/work/project/PhiGraph/src/main.cpp

CMakeFiles/phigraph.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/phigraph.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/work/project/PhiGraph/src/main.cpp > CMakeFiles/phigraph.dir/src/main.cpp.i

CMakeFiles/phigraph.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/phigraph.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/work/project/PhiGraph/src/main.cpp -o CMakeFiles/phigraph.dir/src/main.cpp.s

CMakeFiles/phigraph.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/phigraph.dir/src/main.cpp.o.requires

CMakeFiles/phigraph.dir/src/main.cpp.o.provides: CMakeFiles/phigraph.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/phigraph.dir/build.make CMakeFiles/phigraph.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/phigraph.dir/src/main.cpp.o.provides

CMakeFiles/phigraph.dir/src/main.cpp.o.provides.build: CMakeFiles/phigraph.dir/src/main.cpp.o


# Object files for target phigraph
phigraph_OBJECTS = \
"CMakeFiles/phigraph.dir/src/main.cpp.o"

# External object files for target phigraph
phigraph_EXTERNAL_OBJECTS =

bin/phigraph: CMakeFiles/phigraph.dir/src/main.cpp.o
bin/phigraph: CMakeFiles/phigraph.dir/build.make
bin/phigraph: CMakeFiles/phigraph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wubo/work/project/PhiGraph/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/phigraph"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/phigraph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/phigraph.dir/build: bin/phigraph

.PHONY : CMakeFiles/phigraph.dir/build

CMakeFiles/phigraph.dir/requires: CMakeFiles/phigraph.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/phigraph.dir/requires

CMakeFiles/phigraph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/phigraph.dir/cmake_clean.cmake
.PHONY : CMakeFiles/phigraph.dir/clean

CMakeFiles/phigraph.dir/depend:
	cd /home/wubo/work/project/PhiGraph/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wubo/work/project/PhiGraph /home/wubo/work/project/PhiGraph /home/wubo/work/project/PhiGraph/build /home/wubo/work/project/PhiGraph/build /home/wubo/work/project/PhiGraph/build/CMakeFiles/phigraph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/phigraph.dir/depend

