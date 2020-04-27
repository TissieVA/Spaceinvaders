//
// Created by tijsv on 9/04/2020.
//

#ifndef GAME_ENEMYCONTROLLER_H
#define GAME_ENEMYCONTROLLER_H

#include <vector>
#include "../GameObject/Enemy.h"
#include "../Window/Window.h"
#include "BulletController.h"
#include "../GameObject/BonusShip.h"

using namespace std;

namespace Controllers
{
    class EnemyController
    {
    public:
        EnemyController(int rows, int columns,BulletController* buCo);
        void createEnemies();
        void enqueueEnemies(Window* win);
        void moveEnemies(double timePast,Window* win);

        void removeEnemies();

        const vector<Enemy*> &getEnemyVector() const;

    private:
        vector<Enemy*> enemyVector;
        bool moveRight=true;
        bool bonusRight=true;
        int rows;
        int columns;
        BulletController* buCo;
    };

}

#endif //GAME_ENEMYCONTROLLER_H
