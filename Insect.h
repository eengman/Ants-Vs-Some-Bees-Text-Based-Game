

#ifndef LABASSIGNMENT5_INSECT_H
#define LABASSIGNMENT5_INSECT_H

#include <string>
#include <iostream>
#include "Hive.h"

//#include "Gameboard.h"

using namespace std;

class Insect{

public:
    int armor;
    string name;
    int position;

    Insect();

    virtual void reduceArmor(int amount);

    virtual void action(int &foodBank, vector <Insect*> &vect, vector <Insect*> &vect2) = 0;

    void setPosition(int position);

    int getArmor() const;

    virtual int getPosition()const;

};


#endif //LABASSIGNMENT5_INSECT_H
