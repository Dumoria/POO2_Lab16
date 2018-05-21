//
// Created by benja on 17.05.2018.
//

#ifndef POO2_LAB16_MODEL_H
#define POO2_LAB16_MODEL_H

#include "Parent.h"
#include "Child.h"
#include "Cop.h"
#include "Thief.h"

class Model{
    friend class View;

    Bank* left{};
    Bank* right{};
    Boat* boat{};

public:

    Model() : left(new Bank("Left")), right(new Bank("right")), boat(new Boat("Boat", left)) {
        Parent pere("pere", M), mere("mere", F);
        Child paul("paul", M), pierre("pierre", M), julie("julie", F), jeanne("jeanne", F);
        Cop policier("policier");
        Thief voleur("voleur");
        left->push_back({pere, mere, paul, pierre, julie, jeanne, policier, voleur});
    }

    Bank* getRightBank(){
        return right;
    }

    Bank* getLeftBank(){
        return left;
    }

    Boat* getBoat(){
        return boat;
    }

    //void setRightBank(Bank bank){
    //    right = bank;
    //}
//
    //void setLeftBank(Bank bank){
    //    left = bank;
    //}
//
    //void setBoat(Boat boat){
    //    this->boat = boat;
    //}

};

#endif //POO2_LAB16_MODEL_H
