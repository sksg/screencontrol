# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sorgre/workspace/src/screencontrol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sorgre/workspace/src/screencontrol/build

# Include any dependencies generated for this target.
include CMakeFiles/screencontrol-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/screencontrol-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/screencontrol-test.dir/flags.make

CMakeFiles/screencontrol-test.dir/tests/test.cpp.o: CMakeFiles/screencontrol-test.dir/flags.make
CMakeFiles/screencontrol-test.dir/tests/test.cpp.o: ../tests/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sorgre/workspace/src/screencontrol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/screencontrol-test.dir/tests/test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/screencontrol-test.dir/tests/test.cpp.o -c /Users/sorgre/workspace/src/screencontrol/tests/test.cpp

CMakeFiles/screencontrol-test.dir/tests/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/screencontrol-test.dir/tests/test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sorgre/workspace/src/screencontrol/tests/test.cpp > CMakeFiles/screencontrol-test.dir/tests/test.cpp.i

CMakeFiles/screencontrol-test.dir/tests/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/screencontrol-test.dir/tests/test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sorgre/workspace/src/screencontrol/tests/test.cpp -o CMakeFiles/screencontrol-test.dir/tests/test.cpp.s

# Object files for target screencontrol-test
screencontrol__test_OBJECTS = \
"CMakeFiles/screencontrol-test.dir/tests/test.cpp.o"

# External object files for target screencontrol-test
screencontrol__test_EXTERNAL_OBJECTS =

screencontrol-test: CMakeFiles/screencontrol-test.dir/tests/test.cpp.o
screencontrol-test: CMakeFiles/screencontrol-test.dir/build.make
screencontrol-test: CMakeFiles/screencontrol-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sorgre/workspace/src/screencontrol/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable screencontrol-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/screencontrol-test.dir/link.txt --verbose=$(VERBOSE)
	/usr/local/Cellar/cmake/3.15.5/bin/cmake -D TEST_TARGET=screencontrol-test -D TEST_EXECUTABLE=/Users/sorgre/workspace/src/screencontrol/build/screencontrol-test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/sorgre/workspace/src/screencontrol/build -D TEST_SPEC= -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_LIST=screencontrol-test_TESTS -D CTEST_FILE=/Users/sorgre/workspace/src/screencontrol/build/screencontrol-test_tests-b858cb2.cmake -P /Users/sorgre/workspace/src/screencontrol/Catch2/CatchAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/screencontrol-test.dir/build: screencontrol-test

.PHONY : CMakeFiles/screencontrol-test.dir/build

CMakeFiles/screencontrol-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/screencontrol-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/screencontrol-test.dir/clean

CMakeFiles/screencontrol-test.dir/depend:
	cd /Users/sorgre/workspace/src/screencontrol/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sorgre/workspace/src/screencontrol /Users/sorgre/workspace/src/screencontrol /Users/sorgre/workspace/src/screencontrol/build /Users/sorgre/workspace/src/screencontrol/build /Users/sorgre/workspace/src/screencontrol/build/CMakeFiles/screencontrol-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/screencontrol-test.dir/depend
