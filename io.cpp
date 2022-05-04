#include "io.h"
#include <ncurses.h>

void init_io()
{
    initscr();
    raw();
    noecho();
}

vector<Character *> io_gen_party()
{

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
        int choice = 1;
        do
        {
            clear();
            mvprintw(0, 0, "what type of character would you like to add?");
            refresh();
            input = getch();

        } while (choice);
    }

    return party;
}
