#include "character.h"

#include <string>

string Character::getName() const
{
    return name;
}

int Character::getTurn()
{
    return turn;
}

int Character::getAC() const
{
    return AC;
}

int Character::getHP() const
{
    return HP;
}

void Character::hit(int damage)
{
    HP -= damage;
}

bool Character::hitcheck(int hit)
{
    bool hits = (hit >= AC);
    return hits;
}
