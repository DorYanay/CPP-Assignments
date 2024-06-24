#include "Cowboy.hpp"
#include "Character.hpp"

Cowboy::Cowboy(string name, const Point &location) : Character(name, location, 110), bullets(6) {}
void Cowboy::shoot(Character *enemy)
{
    if (!this->isAlive())
    {
        throw runtime_error("the dead is not a zombie. he is dead.\n");
    }
    if (this == enemy)
    {
        throw runtime_error("I SHALL NOT SELF HARM!\n");
    }
    if (!enemy->isAlive())
    {
        throw runtime_error("ATTACK A DEADMAN? you must be sick\n");
    }
    if (this->hasboolets())
    {
        this->bullets -= 1;
        enemy->hit(10);
    }
}
bool Cowboy::hasboolets() { return bullets > 0; }
void Cowboy::reload()
{
    if (this->isAlive() == 0)
    {
        throw runtime_error("DEADMAN can`t reload\n");
    }

    bullets = 6;
}
void Cowboy::attack(Character *enemy)
{
    if (!this->isAlive())
    {
        return;
    }
    if (this == enemy)
    {
        throw runtime_error("I SHALL NOT SELF HARM!\n");
    }
    if (!enemy->isAlive())
    {
        return;
    }
    if (this->hasboolets())
    {
        this->shoot(enemy);
    }
    else
    {
        this->reload();
    }
}
string Cowboy::print()
{
    if (isAlive())
    {
        return "name: (C)" + this->getName() + ", hit points: " + to_string(this->getHitpoints()) + ", location: " + this->getLocation().print();
    }
    return "name: (C)(" + this->getName() + "), location: " + this->getLocation().print();
}