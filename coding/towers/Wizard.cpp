#include "Wizard.h"

Wizard::Wizard(sf::Vector2i loc) : Tower(loc, wizardDamage, wizardCost, wizardRange)
{
    setTowerTexture(wizardImagePath);
    setTowerSprite();
}

Tower *Wizard::createTower(sf::Vector2i loc)
{
    return new Wizard(loc);
}