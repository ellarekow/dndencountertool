#ifndef __NPC_H__
#define __NPC_H__

#include <string>
#include "character.h"
#include "PC.h"

class NPC : public Character
{
public:
    bool isFriendly;
    bool hitcheck(int hit);
    int genDamage(PC target);
    void hit(int damage);
    NPC(string nm, int armclass, int health);
};

#endif // __NPC_H__