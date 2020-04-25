//
// Created by Tijs Van Alphen on 23/03/2020.
//

#include <cmath>
#include "Player.h"
#include "../Controllers/GameController.h"
using namespace Controllers;

Player::Player(int xpos, int ypos, int width, int height): GameObject(xpos, ypos, width, height)
{
    this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/spaceship.png");
    this->health=3;
}

void Player::KeyDown(Events::Key press) {
    switch (press)
    {
        case Events::Key::LEFT :
            direction= -1;
            break;

        case Events::Key::RIGHT :
            direction = 1;
            break;

        case Events::NOTHING:
            break;
        case Events::SPACE:
            break;
    }
}

void Player::KeyUp(Events::Key press) {
    switch (press)
    {
        case Events::Key::LEFT :
            if(direction < 0)
                direction=0;
            break;

        case Events::Key::RIGHT :
            if(direction >0)
                direction=0;
            break;

        case Events::NOTHING:
            break;

        case Events::SPACE:
            this->shoot=true;
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

void Player::setHealth(int health)
{
    Player::health = health;
}

int Player::getHealth() const
{
    return health;
}
