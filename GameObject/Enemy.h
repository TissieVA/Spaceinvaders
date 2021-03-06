//
// Created by Tijs Van Alphen on 28/03/2020.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "GameObject.h"
#include "../Events/EventObserver.h"
#include "../Controllers/GameController.h"

using namespace SpaceInvaders::Controllers;
using namespace SpaceInvaders::GameObjects;

namespace SpaceInvaders::GameObjects
{
    class Enemy : public GameObject
    {
    public:
        Enemy(int xpos, int ypos, int width, int height);

        void update(double timepast) override;

        void setXDirection(int xDirection);

        void setYDirection(int yDirection);

        void setAlive(bool alive);

        bool isAlive() const;

        bool isCanShoot() const;

        void setCanShoot(bool canShoot);

        void setLevelSpeed(int level);

    protected:
        bool alive;
        bool canShoot = false;
        int xDirection = 0;
        int yDirection = 0;
        double speed = ENEMY_SPEED;
        double levelSpeed =1;
    };
}

#endif //GAME_ENEMY_H
