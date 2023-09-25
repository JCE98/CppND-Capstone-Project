cmake_minimum_required(VERSION 3.11.3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
project(TicTacToe) #Project Name
include_directories(src) #header files
file(GLOB project_SRCS src/*.cpp) #cpp source code files
add_executable(tictactoe ${project_SRCS})