cmake_minimum_required(VERSION 3.10)
project(newStudent)

set(CMAKE_CXX_STANDARD 17)

add_executable(newStudent main.cpp Student.h UI.h UI.cpp Functions.cpp Functions.h)