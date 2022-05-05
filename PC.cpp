#include "PC.h"

PC::PC(string nm, int *health, int *armor)
{
    name = nm;
    HP = health;
    AC = armor;
    turn = 0;
}
