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


#include <iostream>
#include <string>
#include <utility>

enum Gender {F, M};

class Person {
    friend class Container;
protected:
    std::string name;
    Gender gender = M;
    bool _canDrive = true;

public:
    explicit Person(std::string name) : name(std::move(name)) {};
    Person(std::string name, Gender gender) : name(std::move(name)), gender(gender) {};
    Person(Person &p) : name(p.name), gender(p.gender), _canDrive(p._canDrive) {};
    virtual ~Person() {};

    bool operator==(const Person &o) const;
    bool operator!=(const Person &o) const;
    bool operator==(const std::string &s) const;
    bool operator!=(const std::string &s) const;

    friend bool operator==(Person *p, const std::string &s);
    friend bool operator!=(Person *p, const std::string &s);

    friend std::ostream& operator << (std::ostream& os, const Person& person);
    friend std::ostream& operator << (std::ostream& os, const Person* person);

    std::string getName(){
        return name;
    }

    Gender getGender() {
        return gender;
    }

    bool canDrive()const {
        return _canDrive;
    }
};




#endif //POO2_LABO4_GOBET_THOMAS_PERSON_H
