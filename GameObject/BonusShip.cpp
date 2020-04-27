//
// Created by Tijs Van Alphen on 27/04/2020.
//

#include "BonusShip.h"

BonusShip::BonusShip(int xPos, int yPos, int width, int height) : Enemy(xPos, yPos,width,height)
{
    this->sprite = GameController::getInstance().getFactory()->makeSprite("");
    this->alive=true;
}

void BonusShip::update(double timepast)
{
    if(timepast>0)
        move(speed*xDirection*timepast*SCALE_X,0);
}
