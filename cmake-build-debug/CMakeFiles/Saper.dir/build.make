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
CMAKE_COMMAND = /home/samsepiol/programs/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/samsepiol/programs/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/samsepiol/CLionProjects/Minesweeper_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Saper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Saper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Saper.dir/flags.make

CMakeFiles/Saper.dir/main.cpp.o: CMakeFiles/Saper.dir/flags.make
CMakeFiles/Saper.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Saper.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Saper.dir/main.cpp.o -c /home/samsepiol/CLionProjects/Minesweeper_Project/main.cpp

CMakeFiles/Saper.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Saper.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samsepiol/CLionProjects/Minesweeper_Project/main.cpp > CMakeFiles/Saper.dir/main.cpp.i

CMakeFiles/Saper.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Saper.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samsepiol/CLionProjects/Minesweeper_Project/main.cpp -o CMakeFiles/Saper.dir/main.cpp.s

CMakeFiles/Saper.dir/MinesweeperBoard.cpp.o: CMakeFiles/Saper.dir/flags.make
CMakeFiles/Saper.dir/MinesweeperBoard.cpp.o: ../MinesweeperBoard.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Saper.dir/MinesweeperBoard.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Saper.dir/MinesweeperBoard.cpp.o -c /home/samsepiol/CLionProjects/Minesweeper_Project/MinesweeperBoard.cpp

CMakeFiles/Saper.dir/MinesweeperBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Saper.dir/MinesweeperBoard.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samsepiol/CLionProjects/Minesweeper_Project/MinesweeperBoard.cpp > CMakeFiles/Saper.dir/MinesweeperBoard.cpp.i

CMakeFiles/Saper.dir/MinesweeperBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Saper.dir/MinesweeperBoard.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samsepiol/CLionProjects/Minesweeper_Project/MinesweeperBoard.cpp -o CMakeFiles/Saper.dir/MinesweeperBoard.cpp.s

CMakeFiles/Saper.dir/GUI.cpp.o: CMakeFiles/Saper.dir/flags.make
CMakeFiles/Saper.dir/GUI.cpp.o: ../GUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Saper.dir/GUI.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Saper.dir/GUI.cpp.o -c /home/samsepiol/CLionProjects/Minesweeper_Project/GUI.cpp

CMakeFiles/Saper.dir/GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Saper.dir/GUI.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samsepiol/CLionProjects/Minesweeper_Project/GUI.cpp > CMakeFiles/Saper.dir/GUI.cpp.i

CMakeFiles/Saper.dir/GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Saper.dir/GUI.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samsepiol/CLionProjects/Minesweeper_Project/GUI.cpp -o CMakeFiles/Saper.dir/GUI.cpp.s

CMakeFiles/Saper.dir/GUIField.cpp.o: CMakeFiles/Saper.dir/flags.make
CMakeFiles/Saper.dir/GUIField.cpp.o: ../GUIField.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Saper.dir/GUIField.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Saper.dir/GUIField.cpp.o -c /home/samsepiol/CLionProjects/Minesweeper_Project/GUIField.cpp

CMakeFiles/Saper.dir/GUIField.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Saper.dir/GUIField.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/samsepiol/CLionProjects/Minesweeper_Project/GUIField.cpp > CMakeFiles/Saper.dir/GUIField.cpp.i

CMakeFiles/Saper.dir/GUIField.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Saper.dir/GUIField.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/samsepiol/CLionProjects/Minesweeper_Project/GUIField.cpp -o CMakeFiles/Saper.dir/GUIField.cpp.s

# Object files for target Saper
Saper_OBJECTS = \
"CMakeFiles/Saper.dir/main.cpp.o" \
"CMakeFiles/Saper.dir/MinesweeperBoard.cpp.o" \
"CMakeFiles/Saper.dir/GUI.cpp.o" \
"CMakeFiles/Saper.dir/GUIField.cpp.o"

# External object files for target Saper
Saper_EXTERNAL_OBJECTS =

Saper: CMakeFiles/Saper.dir/main.cpp.o
Saper: CMakeFiles/Saper.dir/MinesweeperBoard.cpp.o
Saper: CMakeFiles/Saper.dir/GUI.cpp.o
Saper: CMakeFiles/Saper.dir/GUIField.cpp.o
Saper: CMakeFiles/Saper.dir/build.make
Saper: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
Saper: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
Saper: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
Saper: CMakeFiles/Saper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Saper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Saper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Saper.dir/build: Saper

.PHONY : CMakeFiles/Saper.dir/build

CMakeFiles/Saper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Saper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Saper.dir/clean

CMakeFiles/Saper.dir/depend:
	cd /home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samsepiol/CLionProjects/Minesweeper_Project /home/samsepiol/CLionProjects/Minesweeper_Project /home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug /home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug /home/samsepiol/CLionProjects/Minesweeper_Project/cmake-build-debug/CMakeFiles/Saper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Saper.dir/depend
