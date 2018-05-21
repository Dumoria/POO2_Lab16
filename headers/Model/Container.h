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
protected:
    const std::string name;
    std::list<Person> people;
    unsigned short max = 0;

public:
    explicit Container(std::string name) : name(std::move(name)) {};
    Container(std::string& name, std::initializer_list<Person> args) : Container(name) {
        for (const Person* val = args.begin(); val != args.end(); ++val) {
            people.push_back(*val);
        }
    };
    virtual ~Container() {};
};


#endif //POO2_LABO4_GOBET_THOMAS_CONTAINER_H
