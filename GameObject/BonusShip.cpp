//
// Created by Tijs Van Alphen on 27/04/2020.
//

#include "BonusShip.h"

BonusShip::BonusShip(int xPos, int yPos, int width, int height) : Enemy(xPos, yPos,width,height)
{
    this->sprite = GameController::getInstance().getFactory()->makeSprite("Assets/greenBall.png");
    this->alive=true;
}

void BonusShip::update(double timepast)
{
    if(timepast>0)
        move(speed*xDirection*timepast*SCALE_X,0);
}

void BonusShip::move(double x_direction, double y_direction)
{
    xPos = xPos + x_direction;

    if (yPos + height + y_direction > SCREEN_HEIGHT)
        yPos = SCREEN_HEIGHT - height;

    else if (yPos + y_direction <0)
    {
        yPos = 0;
    }

    else
    {
        yPos += y_direction;
    }
}
