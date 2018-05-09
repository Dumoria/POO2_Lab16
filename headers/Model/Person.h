//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_PERSON_H
#define POO2_LABO4_GOBET_THOMAS_PERSON_H

#include <string>
#include <utility>

class Person{
protected:
    std::string name;
    bool gender;
    bool _canDrive = true;

public:
    Person(std::string name, bool gender) : name(std::move(name)), gender(gender) {};

    bool getGender(){
        return gender;
    }

    bool canDrive() {
        return _canDrive;
    }


};

#endif //POO2_LABO4_GOBET_THOMAS_PERSON_H
