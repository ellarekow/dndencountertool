#ifndef __IO_H__
#define __IO_H__

#include "encounter.h"
#include "character.h"
#include "PC.h"
#include "NPC.h"

#include <vector>

using namespace std;

vector<Character *> io_gen_party();

#endif // __IO_H__