#include "Character.hpp"
#include "SmartTeam.hpp"
#include <vector>

SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
void SmartTeam::attack(Team *enemyTeam)
{
    if (this->stillAlive() == 0)
    {
        throw runtime_error("You cannot rise the dead yet.\n");
    }

    this->setLeader(this->getClosestMember(this));

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
    if (!this->getLeader()->isAlive())
    {
        this->setLeader(this->getClosestMember(this));
    }

    Character *victim = this->getClosestMember(enemyTeam);
    for (Character *member : *this->getTeam())
    {
        if (member->getRole() == "cowboy")
        {
            Character *victim = this->getFarthestMember(member, enemyTeam);
            if (!victim->isAlive())
            {
                victim = this->getFarthestMember(member, enemyTeam);
                if (!victim)
                {
                    return;
                }
            }
            if (member->isAlive())
            {
                member->attack(victim);
            }
        }
        else if (member->getRole() == "ninja")
        {
            Character *victim = this->getClosestMemberSmart(member, enemyTeam);
            if (!victim->isAlive())
            {
                victim = this->getClosestMemberSmart(member, enemyTeam);
                if (!victim)
                {
                    return;
                }
            }
            if (member->isAlive())
            {
                member->attack(victim);
            }
        }
    }
}
void SmartTeam::print()
{
    for (Character *member : *this->getTeam())
    {
        cout << member->print() << endl;
    }
}
