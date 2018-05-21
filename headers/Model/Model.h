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
    friend class Controller;

    Bank* left{};
    Bank* right{};
    Boat* boat{};

public:

    Model() : left(new Bank("Left")), right(new Bank("right")), boat(new Boat("Boat", left)) {
        left->push_back({new Parent("pere", M), new Parent("mere", F),
                         new Child("paul", M), new Child("pierre", M),
                         new Child("julie", F), new Child("jeanne", F),
                         new Cop("policier"), new Thief("voleur")});
    };

    ~Model() {
        delete left;
        delete right;
        delete boat;
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
