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

#include <list>
#include <string>
#include <iostream>
#include "../../headers/Model/Person.h"
#include "../../headers/Model/Container.h"

Container::Container(std::string& name, std::initializer_list<Person*> args) : Container(name) {
    push_back(args);
}

Container::~Container() {
    clear();
}

std::list<Person*> Container::getPeople() {
    return people;
}

const std::list<Person*> Container::getPeople() const {
    return people;
}

const unsigned short Container::getMax() const {
    return max;
}

Container& Container::operator=(const Container& o) {
    if(this != &o) {
        people.clear();
        people = o.people;
        name = o.name;
        max = o.max;
    }
    return *this;
}

/**
 * Store a list of Person in the container
 * @param args the list of people to store
 */
void Container::push_back(std::initializer_list<Person*> args) {
    for (const auto &arg : args) {
        people.push_back(arg);
    }
}

/**
 * Store a Person in the container
 * @param person the person to store
 */
void Container::push_back(Person *person) {
    people.push_back(person);
}

/**
 * Remove someone from the container
 * @param person the person to remove
 */
void Container::remove(Person *person) {
    people.remove(person);
}

/**
 * Clear the container
 */
void Container::clear() {
    people.clear();
}

bool Container::operator==(const Container& o) {
    return this == &o;
};

std::ostream& operator << (std::ostream& os, const std::list<Person*> &people) {
    for (const Person *p: people) {
        os << " " << p;
    }

    return os;
}

std::ostream& operator << (std::ostream& os, const Container& container) {
    os << container.name << ":" << container.people;

    return os;
};

std::ostream& operator << (std::ostream& os, const Container* container) {
    os << container->name << ":" << container->people;

    return os;
};
