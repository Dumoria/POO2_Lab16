//
// Created by benja on 03.05.2018.
//

#ifndef POO2_LABO4_GOBET_THOMAS_CHILD_H
#define POO2_LABO4_GOBET_THOMAS_CHILD_H

class Child : public FamilyMember{

public:

    Child(string name, bool genre);

    bool canDrive(){
        return false;
    }

    bool isParent(){
        return false;
    }

    bool isChild(){
        return true;
    }

};
#endif //POO2_LABO4_GOBET_THOMAS_CHILD_H
