/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 16
File        : Personn.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 10.05.2018
Class       : POO - A

Goal        : Declaration of a personn

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef POO2_LABO4_GOBET_THOMAS_PERSON_H
#define POO2_LABO4_GOBET_THOMAS_PERSON_H


#include <string>
#include <utility>

class Person {
protected:
    std::string name;
    bool gender;
    bool _canDrive;

    Person(std::string name) : name(std::move(name)) {};
    Person(std::string name, bool gender) : name(std::move(name)), gender(gender) {};

    std::string getName(){
        return name;
    }

    bool getGender() {
        return gender;
    }

    bool canDrive() {
        return _canDrive;
    }
};




#endif //POO2_LABO4_GOBET_THOMAS_PERSON_H
