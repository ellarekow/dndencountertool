#include "io.h"
#include "character.h"

#include <vector>

using namespace std;

vector<Character> party;

int main()
{
    init_io();
    io_gen_party();

    return 0;
}