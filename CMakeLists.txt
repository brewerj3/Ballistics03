cmake_minimum_required(VERSION 3.22)
project(Ballistics03 C)

set(CMAKE_C_STANDARD 99)

add_executable(Ballistics03 main.c
        BallisticCalc.h BallisticCalc.c)

target_link_libraries(Ballistics03 m)