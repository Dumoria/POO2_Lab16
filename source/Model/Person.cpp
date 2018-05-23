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

explicit Person::Person(std::string name) : name(std::move(name)) {};

Person::Person(std::string name, Gender gender) : name(std::move(name)), gender(gender) {};

Person::Person(Person &p) : name(p.name), gender(p.gender), _canDrive(p._canDrive) {};

bool Person::operator==(const Person& o) const {
    return this == &o;
}

bool Person::operator==(const std::string& s) const {
    return name == s;
}

bool Person::operator!=(const Person& o) const {
    return !operator==(o);
}

bool Person::operator!=(const std::string& s) const {
    return !operator==(s);
}

bool operator==(Person *p, const std::string &s) {
    return p->getName() == s;
}
bool operator!=(Person *p, const std::string &s) {
    return !operator==(p, s);
}

std::ostream& operator << (std::ostream& os, const Person& person) {
    os << person.name;

    return os;
};

std::ostream& operator << (std::ostream& os, const Person* person) {
    os << person->name;
    return os;
};

std::string Person::getName(){
    return name;
}

Gender Person::getGender() {
    return gender;
}

bool Person::canDrive()const {
    return _canDrive;
}