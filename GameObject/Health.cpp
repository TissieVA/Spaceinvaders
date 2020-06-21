//
// Created by Tijs Van Alphen on 25/04/2020.
//

#include "Health.h"
using namespace SpaceInvaders::Controllers;

Health::Health(int xPos, int yPos, int width, int height) : GameObject(xPos,yPos,width,height )
{
    this->sprite= GameController::getInstance().getFactory()->makeSprite("Assets/heart.png");
}
