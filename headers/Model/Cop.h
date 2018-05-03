//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_COP_H
#define POO2_LABO4_GOBET_THOMAS_COP_H


class Cop : public Person{

public:

    Cop(string name);

    bool canDrive(){
        return true;
    }

    bool isFamilyMember(){
        return false;
    }

    bool isParent(){
        return false;
    }

    bool isChild(){
        return false;
    }

    bool isThief(){
        return false;
    }

    bool isCop(){
        return true;
    }

};

#endif //POO2_LABO4_GOBET_THOMAS_COP_H
