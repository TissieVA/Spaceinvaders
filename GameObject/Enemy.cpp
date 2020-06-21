//
// Created by Tijs Van Alphen on 28/03/2020.
//

#include "Enemy.h"
#include "../Controllers/GameController.h"
#include "../Game.h"

using namespace SpaceInvaders::Controllers;

Enemy::Enemy(int xpos, int ypos, int width, int height) : GameObject(xpos, ypos, width, height)
{
    this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/enemy.png");
    this->alive=true;
    this->xDirection = 1; //set start direction to the right
}

void Enemy::update(double timepast)
{
    if (timepast > 0)
        move(speed * levelSpeed * xDirection * timepast * SCALE_X, yDirection * DROPDOWNAMOUNT *
                                                                   SCALE_Y); //move x direction is speed x timepast x levelspeed | move y direction is dropdown (if ydirection isn't 0 see enemycontroller)
}

void Enemy::setXDirection(int xDirection)
{
    Enemy::xDirection = xDirection;
}

void Enemy::setYDirection(int yDirection)
{
    Enemy::yDirection = yDirection;
}

void Enemy::setAlive(bool alive)
{
    Enemy::alive = alive;
}

bool Enemy::isAlive() const
{
    return alive;
}

void Enemy::setCanShoot(bool canShoot)
{
    Enemy::canShoot = canShoot;
}

bool Enemy::isCanShoot() const
{
    return canShoot;
}

void Enemy::setLevelSpeed(int level)
{
    Enemy::levelSpeed = (SPEED_MULTIPLIER+level-1)/SPEED_MULTIPLIER; //level 1 -> levelspeed =1,
}
