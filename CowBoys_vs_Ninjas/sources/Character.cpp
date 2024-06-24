#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

Character::Character(string name, const Point &location, int hitpoints)
    : name(name), location(location), hitpoints(hitpoints), Team(false) {}
bool Character::isAlive()
{
    return hitpoints > 0;
}
double Character::distance(Character *other)
{
    return this->location.distance(other->location);
}
bool Character::getTeam()
{
    return this->Team;
}
bool Character::setTeam()
{
    return this->Team = true;
}
void Character::hit(int dmg)
{
    if (dmg < 0)
    {
        throw invalid_argument("MISSED BROTHA\n");
    }
    this->hitpoints -= dmg;
}
string Character::getName() { return this->name; }
Point Character::getLocation() const { return this->location; }
void Character::setLocation(Point newLoc)
{
    this->location = newLoc;
}
int Character::getHitpoints()
{
    return this->hitpoints;
}
