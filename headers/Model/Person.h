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

class Person {

private:

    std::string name;

protected:
    explicit Person(std::string name){
        this->name = name;
    }

public:


    std::string getName(){
        return name;
    }

};




#endif //POO2_LABO4_GOBET_THOMAS_PERSON_H
