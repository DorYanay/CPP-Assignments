#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Character.hpp"
#include <climits>

using namespace std;
const int MAX_CAPACITY = 10;
namespace ariel
{
};
class Team
{
    Character *leader;
    vector<Character *> team;

public:
    Character *getFarthestMember(Character *member, Team *team);
    Character *getClosestMemberSmart(Character *member, Team *team);
    Character *getLeader();
    void setLeader(Character *newleader);
    vector<Character *> *getTeam();
    Team(Character *leader);
    Team(Team &&) = default;
    Team(const Team &) = default;
    Team &operator=(Team &&) = default;
    Team &operator=(const Team &) = default;
    void add(Character *);
    void attack(Team *);
    int stillAlive();
    void print();
    Character *getClosestMember(Team *team);
    virtual ~Team();
};
