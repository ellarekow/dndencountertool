#include "NPC.h"
#include "PC.h"

NPC::NPC(string nm, int armclass, int health)
{
    name = nm;
    turn = 0;
    AC = armclass;
    HP = health;
}

bool NPC::hitcheck(int hit)
{
    return hit >= AC;
}

int NPC::genDamage(PC target)
{  
    //choose ability

}

void NPC::hit(int damage)
{
    HP -= damage;
}