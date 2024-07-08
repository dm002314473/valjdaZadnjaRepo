#include "Tower.h"

Tower::Tower(sf::Vector2i loc, int dmg, int cst, int rng)
{
    location = loc;
    damage = dmg;
    cost = cst;
    range = rng;
}

void Tower::setTowerTexture(std::string imagePath)
{
    if (!texture.loadFromFile(imagePath))
    {
        std::cerr << "Unable to load " << imagePath << "!" << std::endl;
        return;
    }
}

void Tower::setTowerSprite() { sprite.setTexture(texture); }

int Tower::getDamage() { return damage; }
int Tower::getCost() { return cost; }
int Tower::getRange() { return range; }