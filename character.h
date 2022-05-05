#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <stdlib.h>
#include <string>

using namespace std;

class Character
{
public:
    string name;
    int *turn;
    int *AC;
    int *HP;

    string getName() const;
    int *getTurn();
    int *getAC();
    int *getHP();
    void hit(int damage);
    bool *hitcheck(int *hit);
};

#endif // __CHARACTER_H__