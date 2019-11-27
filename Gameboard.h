

#ifndef LABASSIGNMENT5_GAMEBOARD_H
#define LABASSIGNMENT5_GAMEBOARD_H

#include <iostream>
#include <vector>
#include "Insect.h"

using namespace std;


class Gameboard{

public:
    vector <Insect*> antV;
    //vector <Insect*> beeV;

    void addInsect(Insect &ant);

};

#endif //LABASSIGNMENT5_GAMEBOARD_H
