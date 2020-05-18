//
// Created by Tijs Van Alphen on 23/03/2020.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "GameObject.h"
#include "../Events/EventObserver.h"

namespace SpaceInvaders::GameObjects
{
    class Player : public SpaceInvaders::GameObjects::GameObject, public SpaceInvaders::Events::EventObserver
    {
    public:
        Player(int xpos, int ypos, int width, int height);

        void KeyUp(SpaceInvaders::Events::Key press) override;

        void KeyDown(SpaceInvaders::Events::Key press) override;

        void update(double timePast) override;

        bool isShoot() const;

        void setShoot(bool shoot);

        int getHealth() const;

        void setHealth(int health);

        bool isRestart() const;

        void setRestart(bool restart);

    private:
        int direction = 0; // no movement
        int health = 3;
        double speed = PLAYER_SPEED;
        bool shoot = false;
        bool restart = false;
    };
}

#endif //GAME_PLAYER_H
