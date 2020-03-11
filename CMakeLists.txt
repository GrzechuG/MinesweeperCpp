cmake_minimum_required(VERSION 3.15)
project(Saper)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS graphics)
add_executable(Saper main.cpp MinesweeperBoard.cpp MinesweeperBoard.h GUI.cpp GUI.h GUIField.cpp GUIField.h)
target_link_libraries(Saper sfml-graphics)