//
// Created by Tijs Van Alphen on 13/04/2020.
//

#ifndef GAME_BULLET_H
#define GAME_BULLET_H


#include "GameObject.h"

class Bullet : public GameObject
{
public:
    Bullet(int xPos, int yPos, int width, int height,int direction, bool enemy);
    void update(double timePast) override;

    void setAlive(bool alive);

    bool isAlive() const;

    int getDirection() const;

private:
    bool alive;
    double speed;
    int direction;
};


#endif //GAME_BULLET_H
