#include "io.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string>
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
            party.push_back(new PC(name, ac, hp));
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
        Character *member;
        member = party.at(i);
        mvprintw(place, 12, "Name: %s, AC: %d, HP: %d", member->getName().c_str(), member->getAC(), member->getHP());
        place++;
    }

    refresh();
    getch();
    noecho();

    return party;
}

vector<Character *> io_encounter_setup()
{
    clear();
    vector<Character *> enemies;

    mvprintw(0, 0, "E N E M I E S");

    echo();
    mvprintw(3, 0, "How many enemies?\n");
    int numEnemies;
    scanw("%d", &numEnemies);

    for (int i = 0; i < numEnemies; i++)
    {
        char tempName[80];
        int hp = 0;
        int ac = 0;
        echo();
        clear();
        mvprintw(0, 0, "E N E M I E S");
        mvprintw(2, 0, "What is the enemies name? \n");
        refresh();
        scanw("%s", tempName);
        string name(tempName);

        mvprintw(3, 0, "What is their current HP? \n");
        refresh();
        scanw("%d", &hp);

        mvprintw(4, 0, "What is their AC? \n");
        refresh();
        scanw("%d", &ac);
        enemies.push_back(new NPC(name, ac, hp));
    }

    clear();
    mvprintw(0, 0, "enemies");
    int place = 0;
    for (unsigned i = 0; i < enemies.size(); i++)
    {
        Character *member;
        member = enemies.at(i);
        mvprintw(place, 12, "Name: %s, AC: %d, HP: %d", member->getName().c_str(), member->getAC(), member->getHP());
        place++;
    }

    refresh();
    getch();
    noecho();

    return enemies;
}

void io_display_info(vector<Character *> party, vector<Character *> enemies)
{
    clear();
    echo();
    int place = 4;
    for (unsigned i = 0; i < party.size(); i++)
    {

        mvprintw(0, 0, "I N I T A T I V E");
        mvprintw(3, 0, "What is %s's Init?\n", party.at(i)->getName().c_str());
        refresh();
        scanw("%d", &party.at(i)->turn);
        clear();
    }

    for (unsigned i = 0; i < enemies.size(); i++)
    {
        mvprintw(3, 0, "ENEMIES");
        Character *member;
        member = enemies.at(i);
        srand(time(NULL));
        member->turn = rand() % 19 + 1;
        mvprintw(place, 12, "Name: %s, AC: %d, HP: %d Turn: %d", member->getName().c_str(), member->getAC(), member->getHP(), member->getTurn());
        place++;
    }

    place += 2;
    mvprintw(place, 0, "PARTY");
    for (unsigned i = 0; i < party.size(); i++)
    {
        Character *member;
        member = party.at(i);
        mvprintw(place, 12, "Name: %s, AC: %d, HP: %d Turn: %d", member->getName().c_str(), member->getAC(), member->getHP(), member->getTurn());
        place++;
    }
    refresh();
    getch();
}

void io_reset_terminal()
{
    endwin();
}