//
// Created by Tijs Van Alphen on 23/03/2020.
//

#include <cmath>
#include "Player.h"
#include "../Controllers/GameController.h"
using namespace SpaceInvaders::Controllers;

Player::Player(int xpos, int ypos, int width, int height): GameObject(xpos, ypos, width, height)
{
    this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/spaceship.png");
    this->health=3;
}

void Player::KeyDown(SpaceInvaders::Events::Key press) {
    switch (press)
    {
        case SpaceInvaders::Events::Key::LEFT :
            direction= -1;
            break;

        case SpaceInvaders::Events::Key::RIGHT :
            direction = 1;
            break;

        case SpaceInvaders::Events::NOTHING:
            break;
        case SpaceInvaders::Events::SPACE:

            break;
    }
}

void Player::KeyUp(SpaceInvaders::Events::Key press) {
    switch (press)
    {
        case SpaceInvaders::Events::Key::LEFT :
            if(direction < 0)
                direction=0;
            break;

        case SpaceInvaders::Events::Key::RIGHT :
            if(direction >0)
                direction=0;
            break;

        case SpaceInvaders::Events::NOTHING:
            break;

        case SpaceInvaders::Events::SPACE:
            this->shoot=true;
            restart = true;
            break;
    }
}

void Player::update(double timePast) {

    move(direction*timePast*speed,0);
    this->shoot=false;

}

bool Player::isShoot() const
{
    return shoot;
}

void Player::setShoot(bool shoot)
{
    Player::shoot = shoot;
}

void Player::setHealth(int health)
{
    Player::health = health;
}

int Player::getHealth() const
{
    return health;
}

bool Player::isRestart() const
{
    return restart;
}

void Player::setRestart(bool restart)
{
    Player::restart = restart;
}

