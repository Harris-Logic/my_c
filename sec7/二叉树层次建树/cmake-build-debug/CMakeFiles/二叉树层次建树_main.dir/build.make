# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/liang/Desktop/c/sec7/二叉树层次建树

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/二叉树层次建树_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/二叉树层次建树_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/二叉树层次建树_main.dir/flags.make

CMakeFiles/二叉树层次建树_main.dir/main.o: CMakeFiles/二叉树层次建树_main.dir/flags.make
CMakeFiles/二叉树层次建树_main.dir/main.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/二叉树层次建树_main.dir/main.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/二叉树层次建树_main.dir/main.o -c /Users/liang/Desktop/c/sec7/二叉树层次建树/main.cpp

CMakeFiles/二叉树层次建树_main.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/二叉树层次建树_main.dir/main.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liang/Desktop/c/sec7/二叉树层次建树/main.cpp > CMakeFiles/二叉树层次建树_main.dir/main.i

CMakeFiles/二叉树层次建树_main.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/二叉树层次建树_main.dir/main.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liang/Desktop/c/sec7/二叉树层次建树/main.cpp -o CMakeFiles/二叉树层次建树_main.dir/main.s

CMakeFiles/二叉树层次建树_main.dir/stack.o: CMakeFiles/二叉树层次建树_main.dir/flags.make
CMakeFiles/二叉树层次建树_main.dir/stack.o: ../stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/二叉树层次建树_main.dir/stack.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/二叉树层次建树_main.dir/stack.o -c /Users/liang/Desktop/c/sec7/二叉树层次建树/stack.cpp

CMakeFiles/二叉树层次建树_main.dir/stack.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/二叉树层次建树_main.dir/stack.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liang/Desktop/c/sec7/二叉树层次建树/stack.cpp > CMakeFiles/二叉树层次建树_main.dir/stack.i

CMakeFiles/二叉树层次建树_main.dir/stack.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/二叉树层次建树_main.dir/stack.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liang/Desktop/c/sec7/二叉树层次建树/stack.cpp -o CMakeFiles/二叉树层次建树_main.dir/stack.s

CMakeFiles/二叉树层次建树_main.dir/queue.o: CMakeFiles/二叉树层次建树_main.dir/flags.make
CMakeFiles/二叉树层次建树_main.dir/queue.o: ../queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/二叉树层次建树_main.dir/queue.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/二叉树层次建树_main.dir/queue.o -c /Users/liang/Desktop/c/sec7/二叉树层次建树/queue.cpp

CMakeFiles/二叉树层次建树_main.dir/queue.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/二叉树层次建树_main.dir/queue.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liang/Desktop/c/sec7/二叉树层次建树/queue.cpp > CMakeFiles/二叉树层次建树_main.dir/queue.i

CMakeFiles/二叉树层次建树_main.dir/queue.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/二叉树层次建树_main.dir/queue.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liang/Desktop/c/sec7/二叉树层次建树/queue.cpp -o CMakeFiles/二叉树层次建树_main.dir/queue.s

# Object files for target 二叉树层次建树_main
二叉树层次建树_main_OBJECTS = \
"CMakeFiles/二叉树层次建树_main.dir/main.o" \
"CMakeFiles/二叉树层次建树_main.dir/stack.o" \
"CMakeFiles/二叉树层次建树_main.dir/queue.o"

# External object files for target 二叉树层次建树_main
二叉树层次建树_main_EXTERNAL_OBJECTS =

二叉树层次建树_main: CMakeFiles/二叉树层次建树_main.dir/main.o
二叉树层次建树_main: CMakeFiles/二叉树层次建树_main.dir/stack.o
二叉树层次建树_main: CMakeFiles/二叉树层次建树_main.dir/queue.o
二叉树层次建树_main: CMakeFiles/二叉树层次建树_main.dir/build.make
二叉树层次建树_main: CMakeFiles/二叉树层次建树_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable 二叉树层次建树_main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/二叉树层次建树_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/二叉树层次建树_main.dir/build: 二叉树层次建树_main

.PHONY : CMakeFiles/二叉树层次建树_main.dir/build

CMakeFiles/二叉树层次建树_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/二叉树层次建树_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/二叉树层次建树_main.dir/clean

CMakeFiles/二叉树层次建树_main.dir/depend:
	cd /Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liang/Desktop/c/sec7/二叉树层次建树 /Users/liang/Desktop/c/sec7/二叉树层次建树 /Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug /Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug /Users/liang/Desktop/c/sec7/二叉树层次建树/cmake-build-debug/CMakeFiles/二叉树层次建树_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/二叉树层次建树_main.dir/depend

