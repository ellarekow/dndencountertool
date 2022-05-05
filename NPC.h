#ifndef __NPC_H__
#define __NPC_H__

#include <string>
#include "character.h"
#include "PC.h"

class NPC : public Character
{
public:
    bool isFriendly;
    // string getName();
    // int getTurn();
    // int getAC();
    // int getHP();
    // void hit(int damage);
    // bool hitcheck(int hit);
    NPC(string nm, int *armclass, int *health);
};

#endif // __NPC_H__