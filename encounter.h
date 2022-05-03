#ifndef __ENCOUNTER_H__
#define __ENCOUNTER_H__

#include <vector>
#include "character.h"

using namespace std;

class encounter
{
public:
    vector<Character> involved;
    int turn;
    int move();
    void addCharacter(Character player);
    void editPart();
    encounter(vector<Character> party);
};
#endif // __ENCOUNTER_H__