#pragma once

#include <..\src\include\SFML\Graphics.hpp>
#include <iostream>

class Enemy
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2i currentlocation;
    int damage;
    int speed;
    int health;

public:
    Enemy(int dmg, int spd, int hlth);
    void setEnemyTexture(std::string imagePath);
    void setEnemySprite();
    virtual Enemy *createEnemy() = 0;
    virtual void  move() = 0;

    int getDamage();
    int getHealth();
    int getSpeed();
    sf::Vector2i getCurrentLocation();
};