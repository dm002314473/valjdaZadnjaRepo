#include "Enemy.h"

Enemy::Enemy(int dmg, int spd, int hlth)
{
    damage = dmg;
    speed = spd;
    health = hlth;
}

void Enemy::setEnemyTexture(std::string imagePath)
{
    if (!texture.loadFromFile(imagePath))
    {
        std::cerr << "Unable to load " << imagePath << "!" << std::endl;
        return;
    }
}

void Enemy::setEnemySprite() { sprite.setTexture(texture); }



int Enemy::getDamage() { return damage; }
int Enemy::getSpeed() { return speed; }
int Enemy::getHealth() { return health; }
sf::Vector2i Enemy::getCurrentLocation() { return currentlocation; }