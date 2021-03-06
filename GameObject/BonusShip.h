//
// Created by Tijs Van Alphen on 27/04/2020.
//

#ifndef GAME_BONUSSHIP_H
#define GAME_BONUSSHIP_H


#include "GameObject.h"
#include "../Controllers/GameController.h"
#include "Enemy.h"

using namespace SpaceInvaders::Controllers;

namespace SpaceInvaders::GameObjects
{
    class BonusShip : public Enemy
    {
    public:
        BonusShip(int xPos, int yPos, int width, int height);

        void update(double timepast) override;

        void move(double x_direction, double y_direction) override;

    protected:
        double speed = BONUSSHIP_SPEED;
    };
}

#endif //GAME_BONUSSHIP_H
