cmake_minimum_required(VERSION 3.30)
project(clion_gcor)

set(CMAKE_CXX_STANDARD 20)

add_executable(clion_gcor main.cpp
        form_cor/FormHandler.cpp
        form_cor/FormHandler.hpp
        form_cor/FormInput.cpp
        form_cor/FormInput.hpp
        form_cor/EmailHandler.cpp
        form_cor/EmailHandler.hpp
        form_cor/TextHandler.cpp
        form_cor/TextHandler.hpp
        form_cor/NumberHandler.cpp
        form_cor/NumberHandler.hpp
        Handler.hpp
        HundredHandler.hpp
        TwentyHandler.hpp
        OneRandHandler.hpp)
