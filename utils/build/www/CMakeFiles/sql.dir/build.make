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
CMAKE_SOURCE_DIR = /home/wubo/project/PhiGraph/utils

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wubo/project/PhiGraph/utils/build

# Include any dependencies generated for this target.
include www/CMakeFiles/sql.dir/depend.make

# Include the progress variables for this target.
include www/CMakeFiles/sql.dir/progress.make

# Include the compile flags for this target's objects.
include www/CMakeFiles/sql.dir/flags.make

www/CMakeFiles/sql.dir/main.cpp.o: www/CMakeFiles/sql.dir/flags.make
www/CMakeFiles/sql.dir/main.cpp.o: ../www/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wubo/project/PhiGraph/utils/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object www/CMakeFiles/sql.dir/main.cpp.o"
	cd /home/wubo/project/PhiGraph/utils/build/www && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sql.dir/main.cpp.o -c /home/wubo/project/PhiGraph/utils/www/main.cpp

www/CMakeFiles/sql.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sql.dir/main.cpp.i"
	cd /home/wubo/project/PhiGraph/utils/build/www && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wubo/project/PhiGraph/utils/www/main.cpp > CMakeFiles/sql.dir/main.cpp.i

www/CMakeFiles/sql.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sql.dir/main.cpp.s"
	cd /home/wubo/project/PhiGraph/utils/build/www && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wubo/project/PhiGraph/utils/www/main.cpp -o CMakeFiles/sql.dir/main.cpp.s

www/CMakeFiles/sql.dir/main.cpp.o.requires:

.PHONY : www/CMakeFiles/sql.dir/main.cpp.o.requires

www/CMakeFiles/sql.dir/main.cpp.o.provides: www/CMakeFiles/sql.dir/main.cpp.o.requires
	$(MAKE) -f www/CMakeFiles/sql.dir/build.make www/CMakeFiles/sql.dir/main.cpp.o.provides.build
.PHONY : www/CMakeFiles/sql.dir/main.cpp.o.provides

www/CMakeFiles/sql.dir/main.cpp.o.provides.build: www/CMakeFiles/sql.dir/main.cpp.o


# Object files for target sql
sql_OBJECTS = \
"CMakeFiles/sql.dir/main.cpp.o"

# External object files for target sql
sql_EXTERNAL_OBJECTS =

bin/sql: www/CMakeFiles/sql.dir/main.cpp.o
bin/sql: www/CMakeFiles/sql.dir/build.make
bin/sql: www/CMakeFiles/sql.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wubo/project/PhiGraph/utils/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/sql"
	cd /home/wubo/project/PhiGraph/utils/build/www && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sql.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
www/CMakeFiles/sql.dir/build: bin/sql

.PHONY : www/CMakeFiles/sql.dir/build

www/CMakeFiles/sql.dir/requires: www/CMakeFiles/sql.dir/main.cpp.o.requires

.PHONY : www/CMakeFiles/sql.dir/requires

www/CMakeFiles/sql.dir/clean:
	cd /home/wubo/project/PhiGraph/utils/build/www && $(CMAKE_COMMAND) -P CMakeFiles/sql.dir/cmake_clean.cmake
.PHONY : www/CMakeFiles/sql.dir/clean

www/CMakeFiles/sql.dir/depend:
	cd /home/wubo/project/PhiGraph/utils/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wubo/project/PhiGraph/utils /home/wubo/project/PhiGraph/utils/www /home/wubo/project/PhiGraph/utils/build /home/wubo/project/PhiGraph/utils/build/www /home/wubo/project/PhiGraph/utils/build/www/CMakeFiles/sql.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : www/CMakeFiles/sql.dir/depend

