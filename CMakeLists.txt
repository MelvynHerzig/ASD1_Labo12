cmake_minimum_required(VERSION 3.16)
project(ASD1_Labo11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wpedantic -Wsign-conversion")

set(CMAKE_CXX_STANDARD 11)

add_executable(ASD1_Labo11 main.cpp taquinSolver.cpp taquinSolver.h)