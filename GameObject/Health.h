//
// Created by Tijs Van Alphen on 25/04/2020.
//

#ifndef GAME_HEALTH_H
#define GAME_HEALTH_H


#include "GameObject.h"
#include "../Controllers/GameController.h"


class Health : public GameObject
{
public:
    Health(int xPos, int yPos, int width, int height);
    void update(double timePast) override;
};


#endif //GAME_HEALTH_H
