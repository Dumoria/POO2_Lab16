/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Implementation of the person

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include "../../headers/Model/Person.h"

bool Person::operator==(const Person& o) {
    return this == &o;
}

std::ostream& operator << (std::ostream& os, const Person& person) {
    os << person.name;

    return os;
};
