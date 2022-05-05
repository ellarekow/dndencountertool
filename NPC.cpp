#include "NPC.h"
#include "PC.h"

NPC::NPC(string nm, int *armclass, int *health)
{
    name = nm;
    turn = 0;
    AC = armclass;
    HP = health;
}

// int NPC::genDamage(PC *target)
// {
//     // choose ability
//     return target->HP;
// }
