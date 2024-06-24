#pragma once
#include "Ninja.hpp"

class OldNinja : public Ninja
{

public:
    OldNinja(string name, const Point &location)
        : Ninja(std::move(name), location, OldHP, OldSpeed) {}
};
