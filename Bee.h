

#ifndef LABASSIGNMENT5_BEE_H
#define LABASSIGNMENT5_BEE_H

#include "Insect.h"
#include "Gameboard.h"

class Bee: public Insect{

public:
    int damage;
    Bee();
    void action(int &foodBank, vector <Insect*> &vect, vector<Insect*> &vect2) override;
    void move(vector <Insect*> vect);
    void sting(Insect &insect, vector <Insect*> &bees, vector<Insect*> &ants);
    void checkRemove(vector<Insect*> &ants);


};

#endif //LABASSIGNMENT5_BEE_H
