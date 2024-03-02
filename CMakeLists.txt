cmake_minimum_required(VERSION 3.26)
project(Lab1_ManageUserAccs)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1_ManageUserAccs main.cpp
        Time.cpp
        Time.h
        DateTime.cpp
        DateTime.h
        User.cpp
        User.h
        Menu.cpp
        Menu.h
        Person.cpp
        Person.h
        UserMenu.cpp
        UserMenu.h)
