cmake_minimum_required(VERSION 3.26)
project(ToDo)

set(CMAKE_CXX_STANDARD 23)

add_executable(ToDo
        src/todo.cpp
        src/todo_manager.h
)
