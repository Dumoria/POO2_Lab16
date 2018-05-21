/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Controller.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Implementation of the boat

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include <string>
#include <iostream>
#include "../../headers/Model/Person.h"
#include "../../headers/Model/Container.h"

Container::Container(std::string& name, std::initializer_list<Person> args) : Container(name) {
        push_back(args);
};

void Container::push_back(std::initializer_list<Person> args) {
    for (const auto &arg : args) {
        people.push_back(arg);
    }
}

bool Container::operator==(const Container& o) {
    return this == &o;
};

std::ostream& operator << (std::ostream& os, const Container& container) {
    os << container.name << ":";

    for (const Person &p: container.people) {
        os << " " << p;
    }

    return os;
};

std::ostream& operator << (std::ostream& os, const Container* container) {
    os << container->name << ":";

    for (const Person &p: container->people) {
        os << " " << p;
    }

    return os;
};
