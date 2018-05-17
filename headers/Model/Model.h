//
// Created by benja on 17.05.2018.
//

#ifndef POO2_LAB16_MODEL_H
#define POO2_LAB16_MODEL_H

class Model{

private:
    Bank right;
    Bank left;
    Boat boat;

public:

    Model model(){
        Parent pere("Père", 0);
        Parent mere("Mère", 1);

        Child paul("Paul", 0);
        Child pierre("Pierre", 0);

        Child julie("Julie", 1);
        Child jeanne("Jeanne", 1);

        Thief thief("Voleur");
        Cop cop("Policier");

        right = new Bank(); //fill with personns, check for insertion in bank
        left = new Bank();
        Boat = new Boat();
    }

    Bank getRightBank(){
        return right;
    }

    Bank getLeftBank(){
        return left;
    }

    Boat getBoat(){
        return boat;
    }

    void setRightBank(Bank bank){
        right = bank;
    }

    void setLeftBank(Bank bank){
        left = bank;
    }

    void setBoat(Boat boat){
        this->boat = boat;
    }

};

#endif //POO2_LAB16_MODEL_H
