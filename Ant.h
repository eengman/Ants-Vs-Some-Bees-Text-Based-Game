

#ifndef LABASSIGNMENT5_ANT_H
#define LABASSIGNMENT5_ANT_H

#include "Insect.h"


class Ant: public Insect {

public:
    int foodCost;
    int foodBank;
    Ant();
    virtual void action(int &foodBank, vector <Insect*> &vect, vector<Insect*> &vect2) = 0;
    void createAnt(int &foodBank);
    bool isAnt();
    ~Ant(){
        cout << "Ant destrcutor" << endl;
        delete this;};

};

class Harvester: public Ant{

public:
    Harvester(int position, int &foodBank);
    void action(int &foodBank, vector <Insect*> &vect, vector<Insect*> &vect2) override;
    ~Harvester(){
        cout << "Destructor called" << endl;
        delete this; }
};

class Thrower: public Ant{

public:
    int damage = 1;

    Thrower(int position, int &foodBank);
    void action(int &foodBank, vector <Insect*> &vect, vector <Insect*> &vector) override;

};

class Fire: public Ant{
public:
    Fire(int position, int &foodBank);
    void action(int &foodBank, vector <Insect*> &vect, vector <Insect*> &vect2) override;

};

class LongThrower: public Ant{
public:
    int minRange;

    LongThrower(int position, int &foodBank);
    void action(int &foodBank, vector <Insect*> &vect, vector <Insect*> &vect2) override;
};

class ShortThrower: public Ant{
public:
    int minRange;

    ShortThrower(int position, int &foodBank);
    void action(int &foodBank, vector <Insect*> &vect, vector <Insect*> &vect2) override;
};

class Wall: public Ant{
public:
    Wall(int position, int &foodBank);
    void action(int &foodBank, vector <Insect*> &vect, vector <Insect*> &vect2) override;
};

class Ninja: public Ant{
public:
    Ninja(int position, int &foodBank);
    void action(int &foodBank, vector <Insect*> &vect, vector <Insect*> &vect2) override;
};

class Bodyguard: public Ant{
public:
    Bodyguard(int position, int &foodBank);
    void action(int &foodBank, vector <Insect*> &vect, vector <Insect*> &vect2) override;
};

#endif //LABASSIGNMENT5_ANT_H
