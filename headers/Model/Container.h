/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Cop.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a container

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_CONTAINER_H
#define POO2_LABO4_GOBET_THOMAS_CONTAINER_H


#include <list>
#include <string>
#include "Person.h"

class Container {
    friend class Person;
protected:
    const std::string name;
    std::list<Person> people;
    unsigned short max = 0;

public:
    Container() {};
    explicit Container(std::string name) : name(std::move(name)) {};
    Container(std::string& name, std::initializer_list<Person> args);
    virtual ~Container() {};

    void push_back(std::initializer_list<Person> args);
    bool operator==(const Container& o);
    friend std::ostream& operator << (std::ostream& os, const Container& container);
    friend std::ostream& operator << (std::ostream& os, const Container* container);

};


#endif //POO2_LABO4_GOBET_THOMAS_CONTAINER_H
