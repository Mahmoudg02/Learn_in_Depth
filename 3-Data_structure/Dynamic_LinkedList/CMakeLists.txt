cmake_minimum_required(VERSION 3.24)
project(Dynamic_LinkedList C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Dynamic_LinkedList
        linkedList.h
        main.c)
