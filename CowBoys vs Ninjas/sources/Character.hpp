#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "Point.hpp"
using namespace std;

class Character
{
    Point location;
    int hitpoints;
    string name;
    string Role;
    bool Team;

public:
    virtual string getRole() = 0;
    bool getTeam();
    bool setTeam();
    Character(string, const Point &, int hitpoints);
    void setLocation(Point);
    bool isAlive();
    int getHitpoints();
    virtual void attack(Character *enemy) = 0;
    double distance(Character *);
    void hit(int dmg);
    string getName();
    Point getLocation() const;
    virtual string print() = 0;
    virtual ~Character() = default;
    Character(const Character &) = default;
    Character &operator=(const Character &) = default;
    Character(Character &&) = default;
    Character &operator=(Character &&) = default;
};
