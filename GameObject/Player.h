//
// Created by Tijs Van Alphen on 23/03/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "GameObject.h"
#include "../Events/EventObserver.h"

class Player: public GameObject, public Events::EventObserver {
public:
    Player(int xpos,int ypos, int width, int height);
    void KeyUp(Events::Key press) override;
    void KeyDown(Events::Key press) override;
    void update(double timePast) override;

    bool isShoot() const;

    int getHealth() const;

    void setHealth(int health);

private:
    int direction=0; // no movement
    int health=3;
    double speed = PLAYER_SPEED;
    bool shoot=false;
};


#endif //GAME_PLAYER_H
