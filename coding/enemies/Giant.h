#pragma once

#include "Enemy.h"
const std::string giantImagePath = "../images/giant.png";
const int giantDamage = 12;
const int giantspeed = 10;
const int giantHealth = 1000;

class Giant : public Enemy
{
public:
    Giant();

    Enemy* createEnemy() override;
    void move() override;
};


