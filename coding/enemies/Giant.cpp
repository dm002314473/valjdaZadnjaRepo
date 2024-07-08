#include "Giant.h"

Giant::Giant() : Enemy(giantDamage, giantspeed, giantHealth) {}






Enemy* createEnemy(){
    Enemy *giant = new Giant();
    return giant;
}