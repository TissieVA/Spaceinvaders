//
// Created by Tijs Van Alphen on 25/04/2020.
//

#include "Health.h"

Health::Health(int xPos, int yPos, int width, int height) : GameObject(xPos,yPos,width,height )
{
    this->sprite= Controllers::GameController::getInstance().getFactory()->makeSprite("Assets/heart.png");
}

void Health::update(double timePast)
{
}