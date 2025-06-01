cmake_minimum_required(VERSION 3.30)
project(clion_gcor)

set(CMAKE_CXX_STANDARD 20)

add_executable(clion_gcor main.cpp
        FormHandler.cpp
        FormHandler.hpp
        FormInput.cpp
        FormInput.hpp
        EmailHandler.cpp
        EmailHandler.hpp
        TextHandler.cpp
        TextHandler.hpp
        NumberHandler.cpp
        NumberHandler.hpp)
