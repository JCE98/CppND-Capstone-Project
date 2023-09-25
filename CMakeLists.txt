cmake_minimum_required(VERSION 3.11.3)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_BUILD_TYPE Debug)
project(TicTacToe) #Project Name
include_directories(src) #cpp source code files
file(GLOB project_SRCS src/*.cpp) #header files
add_executable(tictactoe ${project_SRCS})