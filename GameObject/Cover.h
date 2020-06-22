//
// Created by Tijs Van Alphen on 20/06/2020.
//

#ifndef GAME_COVER_H
#define GAME_COVER_H

#include "GameObject.h"
#include "../Controllers/GameController.h"

using namespace SpaceInvaders::Controllers;
using namespace SpaceInvaders::GameObjects;

namespace SpaceInvaders::GameObjects
{
    class Cover : public GameObject
    {
    public:
        Cover(double xpos, double ypos, int width, int height, int piece);

        void update(double timePast) override {};

        bool isAlive() const;

        void setAlive(bool alive);

    public:
        bool alive;
    };
}
#endif //GAME_COVER_H
