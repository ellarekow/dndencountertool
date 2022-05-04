#ifndef __IO_H__
#define __IO_H__

#include "encounter.h"
#include "character.h"
#include "PC.h"
#include "NPC.h"

#include <vector>
#include <string>

using namespace std;

void init_io();
vector<Character *> io_gen_party();
void io_reset_terminal();

#endif // __IO_H__