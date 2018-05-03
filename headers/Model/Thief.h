//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_THIEF_H
#define POO2_LABO4_GOBET_THOMAS_THIEF_H


class Thief : public Person{

public:

    Thief(string name);

    bool canDrive(){
        return false;
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
        return true;
    }

    bool isCop(){
        return false;
    }

};


#endif //POO2_LABO4_GOBET_THOMAS_THIEF_H
