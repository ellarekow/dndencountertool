#include "io.h"
#include "character.h"

#include <vector>

using namespace std;

vector<Character> party;

int main()
{
    init_io();
    vector<Character *> party = io_gen_party();
    vector<Character *> enemes = io_encounter_setup();
    io_display_info(party, enemes);
    io_reset_terminal();

    return 0;
}