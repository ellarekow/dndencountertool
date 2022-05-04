#include "io.h"
#include <ncurses.h>

vector<Character *> io_gen_party()
{
    initscr();
    raw();
    noecho();

    clear();
    mvprintw(0, 0, "how many in the party?");
    refresh();

    char input = getch();
    int partySize = (int)input - 48;
    clear();

    vector<Character *> party;

    party.push_back(new NPC("test", 14, 10));

    for (int i = 0; i < partySize; i++)
    {
        clear();
        mvprintw(0, 0, "enter character %d information", i + 1);
        refresh();
        getch();
    }

    return party;
}
