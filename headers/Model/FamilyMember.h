//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H
#define POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H


#include "Person.h"

class FamilyMember : public Person{

private:

    bool genre;

public:

    FamilyMember(std::string name, bool gender);

    virtual bool canDrive() = 0;
    virtual bool isParent() = 0;
    virtual bool isChild() = 0;

    bool isFamilyMember(){
        return true;
    }
    bool isThief(){
        return false;
    }
    bool isCop(){
        return false;
    }
    bool getGenre(){
        return genre;
    }


};

#endif //POO2_LABO4_GOBET_THOMAS_FAMILYMEMBER_H
