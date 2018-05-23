cmake_minimum_required(VERSION 3.9)
project(POO2_lab16)

set(CMAKE_CXX_STANDARD 11)

add_executable(POO2_lab16
        main.cpp
        headers/Controller/Controller.h
        headers/Model/Bank.h
        headers/Model/Boat.h
        headers/Model/Child.h
        headers/Model/Container.h
        headers/Model/Cop.h
        headers/Model/FamilyMember.h
        headers/Model/Model.h
        headers/Model/Parent.h
        headers/Model/Person.h
        headers/Model/Rule.h
        headers/Model/Thief.h
        headers/View/View.h
        source/controller/Controller.cpp
        source/Model/Boat.cpp
        source/Model/Container.cpp
        source/Model/Person.cpp
        source/Model/Rule.cpp
        source/view/View.cpp)
