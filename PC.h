#ifndef __PC_H__
#define __PC_H__

#include "character.h"
#include "NPC.h"

#include <string>

class PC : public Character
{
public:
    PC(string nm, int armclass, int health);

    // string getName();
    // int getTurn();
    // int getAC();
    // int getHP();
    // void hit(int damage);
    // bool hitcheck(int hit);
};
#endif // __PC_H__