#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class Tower
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2i location;
    int damage;
    int cost;
    int range;

public:
    Tower(sf::Vector2i loc, int dmg, int cst, int rng);
    void setTowerTexture(std::string imagePath);
    void setTowerSprite();
    virtual Tower *createTower(sf::Vector2i loc) = 0;

    int getDamage();
    int getCost();
    int getRange();
    // Functions needed for upgrading
    // void setDamage();
    // void setCost();
    // void setRange();
};