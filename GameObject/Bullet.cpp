//
// Created by Tijs Van Alphen on 13/04/2020.
//

#include "Bullet.h"
#include "../Controllers/GameController.h"
using namespace SpaceInvaders::Controllers;


Bullet::Bullet(int xPos, int yPos, int width, int height, int direction, bool enemy) : GameObject(xPos, yPos, width,height)
{
    if(enemy)
    {
        this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/redBall.png");
        this->speed = ENEMY_BULLET_SPEED;
    }
    else
    {
        this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/greenBall.png");
        this->speed = PLAYER_BULLET_SPEED;
    }
    this->alive=true;
    this->direction = direction;
}

void Bullet::update(double timePast)
{
    if (timePast > 0)
        move(0,direction*speed*timePast*SCALE_Y);
}


void Bullet::setAlive(bool alive)
{
    Bullet::alive = alive;
}

bool Bullet::isAlive() const
{
    return alive;
}

int Bullet::getDirection() const
{
    return direction;
}
