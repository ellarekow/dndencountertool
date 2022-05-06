#include "io.h"
#include "character.h"

#include <vector>

using namespace std;

vector<Character> party;

int main()
{
    init_io();
    io_gen_party();
    io_encounter_setup();
    io_reset_terminal();

    return 0;
}