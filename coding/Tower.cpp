#include "Tower.h"

Tower::Tower(sf::Vector2i location, int damage) : location(location), damage(damage) {}

Tower *Tower::createTower()
{
    if (!texture.loadFromFile("images/slika.jpg"))
    {
        // throw error
    }
    sprite.setTexture(texture);
}