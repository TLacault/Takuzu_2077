# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/build"

# Include any dependencies generated for this target.
include CMakeFiles/test_mode_error.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_mode_error.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_mode_error.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_mode_error.dir/flags.make

CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o: CMakeFiles/test_mode_error.dir/flags.make
CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o: ../tests/test_mode_error.c
CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o: CMakeFiles/test_mode_error.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o -MF CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o.d -o CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o -c "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/tests/test_mode_error.c"

CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/tests/test_mode_error.c" > CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.i

CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/tests/test_mode_error.c" -o CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.s

# Object files for target test_mode_error
test_mode_error_OBJECTS = \
"CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o"

# External object files for target test_mode_error
test_mode_error_EXTERNAL_OBJECTS =

test_mode_error: CMakeFiles/test_mode_error.dir/tests/test_mode_error.c.o
test_mode_error: CMakeFiles/test_mode_error.dir/build.make
test_mode_error: libgame.a
test_mode_error: CMakeFiles/test_mode_error.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_mode_error"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_mode_error.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_mode_error.dir/build: test_mode_error
.PHONY : CMakeFiles/test_mode_error.dir/build

CMakeFiles/test_mode_error.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_mode_error.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_mode_error.dir/clean

CMakeFiles/test_mode_error.dir/depend:
	cd "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c" "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c" "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/build" "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/build" "/mnt/c/Users/Alexandre L-P/Documents/takuzu-01c/build/CMakeFiles/test_mode_error.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_mode_error.dir/depend

