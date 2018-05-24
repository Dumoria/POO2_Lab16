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
    std::string name;           //The name of the container
    std::list<Person*> people;  //The people that are currently in the container
    unsigned short max = 0;     //The maximum number of people that the container can stock

public:
    Container() {};
    explicit Container(std::string name) : name(std::move(name)) {};
    Container(std::string& name, std::initializer_list<Person*> args);
    virtual ~Container();

    std::list<Person*> getPeople();
    const std::list<Person*> getPeople() const;
    const unsigned short getMax() const;

    /**
     * Store a list of Person in the container
     * @param args the list of people to store
     */
    void push_back(std::initializer_list<Person*> args);

    /**
     * Store a Person in the container
     * @param person the person to store
     */
    void push_back(Person *person);

    /**
     * Remove someone from the container
     * @param person the person to remove
     */
    void remove(Person *person);

    /**
     * Clear the container
     */
    void clear();

    Container& operator=(const Container& o);
    bool operator==(const Container& o);
    friend std::ostream& operator << (std::ostream& os, const std::list<Person> &people);
    friend std::ostream& operator << (std::ostream& os, const Container& container);
    friend std::ostream& operator << (std::ostream& os, const Container* container);

};


#endif //POO2_LABO4_GOBET_THOMAS_CONTAINER_H
