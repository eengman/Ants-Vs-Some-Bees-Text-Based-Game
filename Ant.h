//
// Created by eengm on 11/12/2019.
//

#ifndef LAB5_ANT_H
#define LAB5_ANT_H
#include "Insect.h"

class Ant: public Insect {

public:
    int foodCost;
    Ant();
    virtual void action() = 0;
    void createAnt(int foodBank);

};

class Harvester: public Ant{

public:
    Harvester();
    void action() override;
};

class Thrower: public Ant{

public:
    int damage = 1;

    Thrower();
    void action() override;

};



#endif //LAB5_ANT_H
