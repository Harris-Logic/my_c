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
CMAKE_SOURCE_DIR = /Users/liang/Desktop/c/高级/只出现过一次的那个人

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/liang/Desktop/c/高级/只出现过一次的那个人/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/_m.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_m.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_m.dir/flags.make

CMakeFiles/_m.dir/main.o: CMakeFiles/_m.dir/flags.make
CMakeFiles/_m.dir/main.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/liang/Desktop/c/高级/只出现过一次的那个人/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/_m.dir/main.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/_m.dir/main.o -c /Users/liang/Desktop/c/高级/只出现过一次的那个人/main.cpp

CMakeFiles/_m.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/_m.dir/main.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/liang/Desktop/c/高级/只出现过一次的那个人/main.cpp > CMakeFiles/_m.dir/main.i

CMakeFiles/_m.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/_m.dir/main.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/liang/Desktop/c/高级/只出现过一次的那个人/main.cpp -o CMakeFiles/_m.dir/main.s

# Object files for target _m
_m_OBJECTS = \
"CMakeFiles/_m.dir/main.o"

# External object files for target _m
_m_EXTERNAL_OBJECTS =

_m: CMakeFiles/_m.dir/main.o
_m: CMakeFiles/_m.dir/build.make
_m: CMakeFiles/_m.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/liang/Desktop/c/高级/只出现过一次的那个人/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable _m"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_m.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_m.dir/build: _m

.PHONY : CMakeFiles/_m.dir/build

CMakeFiles/_m.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_m.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_m.dir/clean

CMakeFiles/_m.dir/depend:
	cd /Users/liang/Desktop/c/高级/只出现过一次的那个人/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/liang/Desktop/c/高级/只出现过一次的那个人 /Users/liang/Desktop/c/高级/只出现过一次的那个人 /Users/liang/Desktop/c/高级/只出现过一次的那个人/cmake-build-debug /Users/liang/Desktop/c/高级/只出现过一次的那个人/cmake-build-debug /Users/liang/Desktop/c/高级/只出现过一次的那个人/cmake-build-debug/CMakeFiles/_m.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/_m.dir/depend

