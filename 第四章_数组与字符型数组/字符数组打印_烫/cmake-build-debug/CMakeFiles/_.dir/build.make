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
CMAKE_SOURCE_DIR = /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/_.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_.dir/flags.make

CMakeFiles/_.dir/main.c.o: CMakeFiles/_.dir/flags.make
CMakeFiles/_.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/_.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/_.dir/main.c.o -c /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/main.c

CMakeFiles/_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/main.c > CMakeFiles/_.dir/main.c.i

CMakeFiles/_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/main.c -o CMakeFiles/_.dir/main.c.s

# Object files for target _
__OBJECTS = \
"CMakeFiles/_.dir/main.c.o"

# External object files for target _
__EXTERNAL_OBJECTS =

_ : CMakeFiles/_.dir/main.c.o
_ : CMakeFiles/_.dir/build.make
_ : CMakeFiles/_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable _"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_.dir/build: _

.PHONY : CMakeFiles/_.dir/build

CMakeFiles/_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_.dir/clean

CMakeFiles/_.dir/depend:
	cd /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫 /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫 /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/cmake-build-debug /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/cmake-build-debug /Users/liang/Desktop/c/第四章_数组与字符型数组/字符数组打印_烫/cmake-build-debug/CMakeFiles/_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/_.dir/depend

