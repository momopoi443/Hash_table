cmake_minimum_required(VERSION 3.21)
project(lab2_1_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2_1_0
        src/main.cpp
        src/HashTab.cpp include/HashTab.h
        src/Data.cpp include/Data.h
        src/LinkedList.cpp include/LinkedList.h)
