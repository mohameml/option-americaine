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
CMAKE_SOURCE_DIR = /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/build

# Include any dependencies generated for this target.
include CMakeFiles/mc-example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mc-example.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mc-example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mc-example.dir/flags.make

CMakeFiles/mc-example.dir/src/mc_example.cpp.o: CMakeFiles/mc-example.dir/flags.make
CMakeFiles/mc-example.dir/src/mc_example.cpp.o: ../src/mc_example.cpp
CMakeFiles/mc-example.dir/src/mc_example.cpp.o: CMakeFiles/mc-example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mc-example.dir/src/mc_example.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mc-example.dir/src/mc_example.cpp.o -MF CMakeFiles/mc-example.dir/src/mc_example.cpp.o.d -o CMakeFiles/mc-example.dir/src/mc_example.cpp.o -c /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/src/mc_example.cpp

CMakeFiles/mc-example.dir/src/mc_example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mc-example.dir/src/mc_example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/src/mc_example.cpp > CMakeFiles/mc-example.dir/src/mc_example.cpp.i

CMakeFiles/mc-example.dir/src/mc_example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mc-example.dir/src/mc_example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/src/mc_example.cpp -o CMakeFiles/mc-example.dir/src/mc_example.cpp.s

# Object files for target mc-example
mc__example_OBJECTS = \
"CMakeFiles/mc-example.dir/src/mc_example.cpp.o"

# External object files for target mc-example
mc__example_EXTERNAL_OBJECTS =

mc-example: CMakeFiles/mc-example.dir/src/mc_example.cpp.o
mc-example: CMakeFiles/mc-example.dir/build.make
mc-example: /home/mohameml/ENSIMAG/3A/MEQA/S9/04_methodes_Monte_Carlo/TPs/pnl/lib/libpnl.so
mc-example: /usr/lib/x86_64-linux-gnu/libblas.so
mc-example: /usr/lib/x86_64-linux-gnu/liblapack.so
mc-example: /usr/lib/x86_64-linux-gnu/libblas.so
mc-example: /usr/lib/x86_64-linux-gnu/liblapack.so
mc-example: CMakeFiles/mc-example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mc-example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mc-example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mc-example.dir/build: mc-example
.PHONY : CMakeFiles/mc-example.dir/build

CMakeFiles/mc-example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mc-example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mc-example.dir/clean

CMakeFiles/mc-example.dir/depend:
	cd /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/build /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/build /home/mohameml/ENSIMAG/3A/MEQA/S9/05_options_americaines/Projet/option-americaine/build/CMakeFiles/mc-example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mc-example.dir/depend

