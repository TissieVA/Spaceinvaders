//
// Created by Tijs Van Alphen on 28/03/2020.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "GameObject.h"
#include "../Events/EventObserver.h"
#include "../Controllers/GameController.h"

using namespace Controllers;

class Enemy : public GameObject {
public:
    Enemy(int xpos, int ypos, int width, int height);
    void update(double timepast) override;

    void setXDirection(int xDirection);

    void setYDirection(int yDirection);

    void setAlive(bool alive);

    bool isAlive() const;

protected:
    bool alive;
    int xDirection=0;
    int yDirection=0;
    double speed = ENEMY_SPEED;
};


#endif //GAME_ENEMY_H
