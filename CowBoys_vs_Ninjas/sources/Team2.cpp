#include "Character.hpp"
#include "Team2.hpp"

Team2::Team2(Character *leader) : Team(leader) {}
void Team2::attack(Team *enemyTeam)
{
    if (this->stillAlive() == 0)
    {
        throw runtime_error("You cannot rise the dead yet.\n");
    }
    if (!this->getLeader()->isAlive())
    {
        this->setLeader(getClosestMember(this));
    }

    if (this == enemyTeam)
    {
        throw runtime_error("im no Masochist. I WON`T HARM MYSELF!\n");
    }
    if (!enemyTeam)
    {
        throw invalid_argument("WHERE IS THE ENEMY TEAM?!\n");
    }
    if (!enemyTeam->stillAlive())
    {
        throw runtime_error("You are defiling corpses\n");
    }

    Character *victim = getClosestMember(enemyTeam);
    for (Character *member : *this->getTeam())
    {
        if (!victim->isAlive())
        {
            victim = getClosestMember(enemyTeam);
            if (!victim)
            {
                return;
            }
        }
        member->attack(victim);
    }
}
void Team2::print()
{
    for (Character *member : *this->getTeam())
    {
        cout << member->print() << endl;
    }
}
