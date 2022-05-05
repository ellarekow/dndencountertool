#include "io.h"
#include <ncurses.h>
#include <bits/stdc++.h>

void init_io()
{
    initscr();
    raw();
    noecho();
}

vector<Character *> io_gen_party()
{
    echo();
    clear();
    mvprintw(0, 0, "how many in the party?");
    refresh();

    char input;

    int partySize = 0;

    scanw("%d", &partySize);

    clear();

    vector<Character *> party;

    mvprintw(0, 0, "P A R T Y  C R E A T I O N");

    for (int i = 0; i < partySize; i++)
    {
        noecho();
        int arrow_y = 3;
        int choice = 1;
        bool pc = true;
        do
        {
            clear();
            mvprintw(0, 0, "P A R T Y  C R E A T I O N");
            mvprintw(2, 0, "what type of character would you like to add for character %d? (use arrow keys)", i + 1);
            mvprintw(3, 5, "NPC (non playable character)");
            mvprintw(4, 5, "PC (playable character)");
            mvprintw(arrow_y, 4, ">");
            refresh();
            switch (input = getch())
            {
            case 65:
                if (arrow_y > 3)
                {
                    pc = false;
                    arrow_y--;
                }
                break;

            case 66:
                if (arrow_y < 4)
                {
                    pc = true;
                    arrow_y++;
                }
                break;

            case 10:
                choice = 0;
                break;

            default:
                mvprintw(0, 0, "Please enter a valid input.");
            }
        } while (choice);
        char tempName[80];
        int hp = 0;
        int ac = 0;
        echo();
        clear();
        mvprintw(0, 0, "P A R T Y  C R E A T I O N");
        mvprintw(2, 0, "What is your characters name? \n");
        refresh();
        scanw("%s", tempName);
        string name(tempName);

        mvprintw(3, 0, "What is their current HP? \n");
        refresh();
        scanw("%d", &hp);

        mvprintw(4, 0, "What is their AC? \n");
        refresh();
        scanw("%d", &ac);

        if (pc == true)
        {
        }
        else
        {
            party.push_back(new NPC(name, ac, hp));
        }
    }

    clear();

    mvprintw(0, 0, "party");
    int place = 0;
    for (unsigned i = 0; i < party.size(); i++)
    {
        mvprintw(place, 12, ", %s", party.at(i)->name.c_str());
        place++;
    }

    refresh();
    getch();
    noecho();

    return party;
}

void io_reset_terminal()
{
    endwin();
}