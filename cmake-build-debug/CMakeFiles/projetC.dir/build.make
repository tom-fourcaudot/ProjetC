# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /Users/matisbouquin/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/matisbouquin/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ProjetC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProjetC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjetC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetC.dir/flags.make

CMakeFiles/ProjetC.dir/main.c.o: CMakeFiles/ProjetC.dir/flags.make
CMakeFiles/ProjetC.dir/main.c.o: /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/main.c
CMakeFiles/ProjetC.dir/main.c.o: CMakeFiles/ProjetC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjetC.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjetC.dir/main.c.o -MF CMakeFiles/ProjetC.dir/main.c.o.d -o CMakeFiles/ProjetC.dir/main.c.o -c /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/main.c

CMakeFiles/ProjetC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetC.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/main.c > CMakeFiles/ProjetC.dir/main.c.i

CMakeFiles/ProjetC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetC.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/main.c -o CMakeFiles/ProjetC.dir/main.c.s

CMakeFiles/ProjetC.dir/Rope/Node.c.o: CMakeFiles/ProjetC.dir/flags.make
CMakeFiles/ProjetC.dir/Rope/Node.c.o: /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/Node.c
CMakeFiles/ProjetC.dir/Rope/Node.c.o: CMakeFiles/ProjetC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjetC.dir/Rope/Node.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjetC.dir/Rope/Node.c.o -MF CMakeFiles/ProjetC.dir/Rope/Node.c.o.d -o CMakeFiles/ProjetC.dir/Rope/Node.c.o -c /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/Node.c

CMakeFiles/ProjetC.dir/Rope/Node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetC.dir/Rope/Node.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/Node.c > CMakeFiles/ProjetC.dir/Rope/Node.c.i

CMakeFiles/ProjetC.dir/Rope/Node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetC.dir/Rope/Node.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/Node.c -o CMakeFiles/ProjetC.dir/Rope/Node.c.s

CMakeFiles/ProjetC.dir/Rope/Rope.c.o: CMakeFiles/ProjetC.dir/flags.make
CMakeFiles/ProjetC.dir/Rope/Rope.c.o: /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/Rope.c
CMakeFiles/ProjetC.dir/Rope/Rope.c.o: CMakeFiles/ProjetC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ProjetC.dir/Rope/Rope.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjetC.dir/Rope/Rope.c.o -MF CMakeFiles/ProjetC.dir/Rope/Rope.c.o.d -o CMakeFiles/ProjetC.dir/Rope/Rope.c.o -c /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/Rope.c

CMakeFiles/ProjetC.dir/Rope/Rope.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetC.dir/Rope/Rope.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/Rope.c > CMakeFiles/ProjetC.dir/Rope/Rope.c.i

CMakeFiles/ProjetC.dir/Rope/Rope.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetC.dir/Rope/Rope.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/Rope.c -o CMakeFiles/ProjetC.dir/Rope/Rope.c.s

CMakeFiles/ProjetC.dir/Rope/String.c.o: CMakeFiles/ProjetC.dir/flags.make
CMakeFiles/ProjetC.dir/Rope/String.c.o: /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/String.c
CMakeFiles/ProjetC.dir/Rope/String.c.o: CMakeFiles/ProjetC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ProjetC.dir/Rope/String.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjetC.dir/Rope/String.c.o -MF CMakeFiles/ProjetC.dir/Rope/String.c.o.d -o CMakeFiles/ProjetC.dir/Rope/String.c.o -c /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/String.c

CMakeFiles/ProjetC.dir/Rope/String.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ProjetC.dir/Rope/String.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/String.c > CMakeFiles/ProjetC.dir/Rope/String.c.i

CMakeFiles/ProjetC.dir/Rope/String.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ProjetC.dir/Rope/String.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/Rope/String.c -o CMakeFiles/ProjetC.dir/Rope/String.c.s

# Object files for target ProjetC
ProjetC_OBJECTS = \
"CMakeFiles/ProjetC.dir/main.c.o" \
"CMakeFiles/ProjetC.dir/Rope/Node.c.o" \
"CMakeFiles/ProjetC.dir/Rope/Rope.c.o" \
"CMakeFiles/ProjetC.dir/Rope/String.c.o"

# External object files for target ProjetC
ProjetC_EXTERNAL_OBJECTS =

ProjetC: CMakeFiles/ProjetC.dir/main.c.o
ProjetC: CMakeFiles/ProjetC.dir/Rope/Node.c.o
ProjetC: CMakeFiles/ProjetC.dir/Rope/Rope.c.o
ProjetC: CMakeFiles/ProjetC.dir/Rope/String.c.o
ProjetC: CMakeFiles/ProjetC.dir/build.make
ProjetC: CMakeFiles/ProjetC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable ProjetC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProjetC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetC.dir/build: ProjetC
.PHONY : CMakeFiles/ProjetC.dir/build

CMakeFiles/ProjetC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ProjetC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ProjetC.dir/clean

CMakeFiles/ProjetC.dir/depend:
	cd /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug /Users/matisbouquin/Documents/Travail/IUT/S5/ProjetC/ProjetC/cmake-build-debug/CMakeFiles/ProjetC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ProjetC.dir/depend

