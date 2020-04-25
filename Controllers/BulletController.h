//
// Created by Tijs Van Alphen on 14/04/2020.
//

#ifndef GAME_BULLETCONTROLLER_H
#define GAME_BULLETCONTROLLER_H

#include "../GameObject/Bullet.h"
#include "../Window/Window.h"
#include "../GameObject/Enemy.h"
#include "../GameObject/Player.h"
#include <vector>
using namespace std;

namespace Controllers
{

    class BulletController
    {
    public:
        BulletController(Player* player);

        void addBullet(int xPos, int yPos,int direction,bool fromEnemy);
        void enqueueBullets(Window* win);
        void moveBullets(double timePast, vector<Enemy*> enemyVector);

        int getScore() const;

    private:
        vector<Bullet*> bulletVector;
        Player* player;
        int score =0;
    };

}
#endif //GAME_BULLETCONTROLLER_H
