# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/workspace/CppND-Capstone-Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/workspace/CppND-Capstone-Project/builds

# Include any dependencies generated for this target.
include CMakeFiles/tictactoe.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tictactoe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tictactoe.dir/flags.make

CMakeFiles/tictactoe.dir/src/board.cpp.o: CMakeFiles/tictactoe.dir/flags.make
CMakeFiles/tictactoe.dir/src/board.cpp.o: ../src/board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-Project/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tictactoe.dir/src/board.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoe.dir/src/board.cpp.o -c /home/workspace/CppND-Capstone-Project/src/board.cpp

CMakeFiles/tictactoe.dir/src/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoe.dir/src/board.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-Project/src/board.cpp > CMakeFiles/tictactoe.dir/src/board.cpp.i

CMakeFiles/tictactoe.dir/src/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoe.dir/src/board.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-Project/src/board.cpp -o CMakeFiles/tictactoe.dir/src/board.cpp.s

CMakeFiles/tictactoe.dir/src/main.cpp.o: CMakeFiles/tictactoe.dir/flags.make
CMakeFiles/tictactoe.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-Project/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tictactoe.dir/src/main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoe.dir/src/main.cpp.o -c /home/workspace/CppND-Capstone-Project/src/main.cpp

CMakeFiles/tictactoe.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoe.dir/src/main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-Project/src/main.cpp > CMakeFiles/tictactoe.dir/src/main.cpp.i

CMakeFiles/tictactoe.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoe.dir/src/main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-Project/src/main.cpp -o CMakeFiles/tictactoe.dir/src/main.cpp.s

CMakeFiles/tictactoe.dir/src/player.cpp.o: CMakeFiles/tictactoe.dir/flags.make
CMakeFiles/tictactoe.dir/src/player.cpp.o: ../src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/workspace/CppND-Capstone-Project/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tictactoe.dir/src/player.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tictactoe.dir/src/player.cpp.o -c /home/workspace/CppND-Capstone-Project/src/player.cpp

CMakeFiles/tictactoe.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tictactoe.dir/src/player.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/workspace/CppND-Capstone-Project/src/player.cpp > CMakeFiles/tictactoe.dir/src/player.cpp.i

CMakeFiles/tictactoe.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tictactoe.dir/src/player.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/workspace/CppND-Capstone-Project/src/player.cpp -o CMakeFiles/tictactoe.dir/src/player.cpp.s

# Object files for target tictactoe
tictactoe_OBJECTS = \
"CMakeFiles/tictactoe.dir/src/board.cpp.o" \
"CMakeFiles/tictactoe.dir/src/main.cpp.o" \
"CMakeFiles/tictactoe.dir/src/player.cpp.o"

# External object files for target tictactoe
tictactoe_EXTERNAL_OBJECTS =

tictactoe: CMakeFiles/tictactoe.dir/src/board.cpp.o
tictactoe: CMakeFiles/tictactoe.dir/src/main.cpp.o
tictactoe: CMakeFiles/tictactoe.dir/src/player.cpp.o
tictactoe: CMakeFiles/tictactoe.dir/build.make
tictactoe: CMakeFiles/tictactoe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/workspace/CppND-Capstone-Project/builds/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable tictactoe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tictactoe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tictactoe.dir/build: tictactoe

.PHONY : CMakeFiles/tictactoe.dir/build

CMakeFiles/tictactoe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tictactoe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tictactoe.dir/clean

CMakeFiles/tictactoe.dir/depend:
	cd /home/workspace/CppND-Capstone-Project/builds && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/workspace/CppND-Capstone-Project /home/workspace/CppND-Capstone-Project /home/workspace/CppND-Capstone-Project/builds /home/workspace/CppND-Capstone-Project/builds /home/workspace/CppND-Capstone-Project/builds/CMakeFiles/tictactoe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tictactoe.dir/depend

