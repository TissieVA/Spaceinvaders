//
// Created by Tijs Van Alphen on 13/04/2020.
//

#include "Bullet.h"
#include "../Controllers/GameController.h"
using namespace SpaceInvaders::Controllers;


Bullet::Bullet(int xPos, int yPos, int width, int height, int direction, bool enemy) : GameObject(xPos, yPos, width,height)
{
    if(enemy) //if from enemy, the sprite and speed is different
    {
        this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/EnemyBullet.png");
        this->speed = ENEMY_BULLET_SPEED;
    }
    else
    {
        this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/PlayerBullet.png");
        this->speed = PLAYER_BULLET_SPEED;
    }
    this->alive=true;
    this->direction = direction;
}

void Bullet::update(double timePast)
{
    if (timePast > 0)
        move(0,direction*speed*timePast*SCALE_Y); //amount moved is timepast times speed
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
