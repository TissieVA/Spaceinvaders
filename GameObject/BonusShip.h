//
// Created by Tijs Van Alphen on 27/04/2020.
//

#ifndef GAME_BONUSSHIP_H
#define GAME_BONUSSHIP_H


#include "GameObject.h"
#include "../Controllers/GameController.h"
#include "Enemy.h"

using namespace Controllers;

class BonusShip : public Enemy
{
public:
    BonusShip(int xPos, int yPos, int width, int height);
    void update(double timepast) override;

protected:
    double speed = BONUSSHIP_SPEED;
};


#endif //GAME_BONUSSHIP_H
