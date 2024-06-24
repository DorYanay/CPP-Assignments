#include "Character.hpp"
#include "Team.hpp"
#include <vector>
using namespace std;
Team::Team(Character *leader) : leader(leader)
{
    if (leader->getTeam())
    {
        throw runtime_error("Going behind the enemy rank? not on my watch.\n");
    }
    team.push_back(leader);
    leader->setTeam();
}
Team::~Team()
{
    for (Character *member : team)
    {
        delete member;
    }
}
void Team::add(Character *member)
{

    if (team.size() == 10 || member->getTeam())
    {
        throw runtime_error("hmm hmm cough cough GOTCHA!\n");
    }
    team.push_back(member);
    member->setTeam();
}

Character *Team::getClosestMember(Team *other)
{
    Character *closestCharacter = nullptr;
    double minDistance = __DBL_MAX__;

    for (Character *member : other->team)
    {
        if (member->isAlive())
        {
            if (this->leader->distance(member) < minDistance)
            {
                minDistance = this->leader->distance(member);
                closestCharacter = member;
            }
        }
    }

    return closestCharacter;
}
Character *Team::getClosestMemberSmart(Character *teammate, Team *other)
{
    Character *closestCharacter = nullptr;
    double minDistance = __DBL_MAX__;

    for (Character *member : other->team)
    {
        if (member->isAlive())
        {
            if (teammate->distance(member) < minDistance)
            {
                minDistance = teammate->distance(member);
                closestCharacter = member;
            }
        }
    }

    return closestCharacter;
}
Character *Team::getFarthestMember(Character *teammate, Team *other)
{
    Character *farthestCharacter = nullptr;
    double maxDistance = __DBL_MIN__;

    for (Character *member : other->team)
    {
        if (member->isAlive())
        {
            if (teammate->distance(member) > maxDistance)
            {
                maxDistance = teammate->distance(member);
                farthestCharacter = member;
            }
        }
    }

    return farthestCharacter;
}
void Team::attack(Team *enemyTeam)
{
    if (this->stillAlive() == 0)
    {
        throw runtime_error("You cannot rise the dead yet.\n");
    }
    if (this->leader->isAlive() == 0)
    {
        this->leader = getClosestMember(this);
    }

    if (this == enemyTeam)
    {
        throw runtime_error("im no Masochist. I WON`T HARM MYSELF!\n");
    }
    if (!enemyTeam)
    {
        throw invalid_argument("WHERE IS THE ENEMY TEAM?!\n");
    }
    if (enemyTeam->stillAlive() == 0)
    {
        throw runtime_error("You are defiling corpses\n");
    }
    Character *victim = getClosestMember(enemyTeam);
    for (Character *member : team)
    {
        if (member->getRole() == "cowboy")
        {
            if (!victim->isAlive())
            {
                victim = getClosestMember(enemyTeam);
                if (victim == nullptr)
                    return;
            }
            member->attack(victim);
        }
        else
        {
            continue;
        }
    }
    for (Character *member : team)
    {
        if (member->getRole() == "ninja")
        {
            if (!victim->isAlive())
            {
                victim = getClosestMember(enemyTeam);
                if (victim == nullptr)
                    return;
            }
            member->attack(victim);
        }
        else
        {
            continue;
        }
    }
}
int Team::stillAlive()
{
    int alive = 0;
    for (Character *member : team)
    {
        if (member->isAlive())
        {
            alive++;
        }
    }
    return alive;
}
void Team::print()
{
    for (Character *member : team)
    {
        if (member->getRole() == "cowboy")
        {
            cout << member->print() << endl;
        }
    }
    for (Character *member : team)
    {
        if (member->getRole() == "ninja")
        {
            cout << member->print() << endl;
        }
    }
    cout << endl;
}

Character *Team::getLeader()
{
    return this->leader;
}
void Team::setLeader(Character *newLeader)
{
    this->leader = newLeader;
}
vector<Character *> *Team::getTeam()
{
    return &team;
}