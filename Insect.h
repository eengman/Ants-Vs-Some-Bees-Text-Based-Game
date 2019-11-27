

#ifndef LAB5_INSECT_H
#define LAB5_INSECT_H

#include <string>
#include <iostream>
#include "B.h"

using namespace std;

class Insect{

public:
    int armor;
    string name;
    int position;

    Insect();

    virtual void reduceArmor(int amount);

    virtual void action() = 0;

    void setPosition(int position);

    int getArmor() const;

    virtual int getPosition()const;

};



#endif //LAB5_INSECT_H
