//
// Created by Tijs Van Alphen on 14/04/2020.
//

#ifndef GAME_BULLETCONTROLLER_H
#define GAME_BULLETCONTROLLER_H

#include "../GameObject/Bullet.h"
#include "../Window/Window.h"
#include "../GameObject/Enemy.h"
#include "../GameObject/Player.h"
#include "../GameObject/BonusShip.h"
#include <vector>
using namespace std;

namespace SpaceInvaders::Controllers
{

    class BulletController
    {
    public:
        BulletController(Player* player);

        void addBullet(int xPos, int yPos,int direction,bool fromEnemy);
        void enqueueBullets(SpaceInvaders::Window::Window* win);
        void moveBullets(double timePast, vector<Enemy*> enemyVector, vector<BonusShip*> bonusVector);
        void removeBullets();

        int getScore() const;

        void setScore(int score);

        virtual ~BulletController();

    private:
        vector<Bullet*> bulletVector;
        Player* player;
        int score =0;
    };
}
#endif //GAME_BULLETCONTROLLER_H
