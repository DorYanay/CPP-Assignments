#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Team.hpp"
using namespace std;
class Team2 : public Team
{
public:
    Team2(Character *leader);
    void attack(Team *);
    void print();
};
