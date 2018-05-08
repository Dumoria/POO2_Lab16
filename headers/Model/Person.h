//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_PERSON_H
#define POO2_LABO4_GOBET_THOMAS_PERSON_H

<<<<<<< HEAD
#include <string>

class Person{
    std::string name;
    bool gender;
    bool _canDrive = true;

public:
    Person(std::string name, bool gender) : name(name), gender(gender) {};

    bool getGender(){
        return gender;
    }

    bool canDrive() {
        return _canDrive;
    }

=======
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
>>>>>>> master

};

#endif //POO2_LABO4_GOBET_THOMAS_PERSON_H
