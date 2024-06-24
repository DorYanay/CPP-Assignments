#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
using namespace std;
class SmartTeam : public Team
{

public:
    SmartTeam(Character *leader);
    void attack(Team *);
    void print();
};
