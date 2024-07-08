#pragma once

#include "Tower.h"

const std::string wizardImagePath = "../images/wiz_lvl1.png";
const int wizardDamage = 12;
const int wizardCost = 100;
const int wizardRange = 1;

class Wizard : public Tower
{
public:
    Wizard(sf::Vector2i loc);
    virtual Tower *createTower(sf::Vector2i loc) override;
};