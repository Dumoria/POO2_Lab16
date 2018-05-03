//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_PERSON_H
#define POO2_LABO4_GOBET_THOMAS_PERSON_H

class Person{

private:

    string name;

public:

    Person(string name);
    virtual bool canDrive() = 0;
    virtual bool isFamilyMember() = 0;
    virtual bool isParent() = 0;
    virtual bool isChild() = 0;
    virtual bool isThief() = 0;
    virtual bool isCop() = 0;

};

#endif //POO2_LABO4_GOBET_THOMAS_PERSON_H
