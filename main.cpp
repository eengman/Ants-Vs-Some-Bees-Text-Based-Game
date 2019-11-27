#include <iostream>
#include <vector>
#include <string>
#include "Insect.h"
#include "Gameboard.h"
#include "Ant.h"

using namespace std;

int main() {

    Harvester harv;
    Thrower thrower;
    Gameboard board[10];

    board[0].addInsect(bee);
    board[0].addInsect(thrower);

    board[0].v[1]->action(bee);


    return 0;
}