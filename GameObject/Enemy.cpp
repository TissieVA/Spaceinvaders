//
// Created by Tijs Van Alphen on 28/03/2020.
//

#include "Enemy.h"
#include "../Controllers/GameController.h"
using namespace SpaceInvaders::Controllers;

Enemy::Enemy(int xpos, int ypos, int width, int height) : GameObject(xpos, ypos, width, height)
{
    this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/enemy.png");
    this->alive=true;
    this->xDirection = 1;
}

void Enemy::update(double timepast)
{
    if (timepast >0)
        move(speed*xDirection*timepast*SCALE_X,yDirection*DROPDOWNAMOUNT*SCALE_Y);
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
