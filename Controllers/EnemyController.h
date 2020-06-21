//
// Created by tijsv on 9/04/2020.
//

#ifndef GAME_ENEMYCONTROLLER_H
#define GAME_ENEMYCONTROLLER_H

#include <vector>
#include "../GameObject/Enemy.h"
#include "../Window/Window.h"
#include "BulletController.h"

using namespace std;

namespace SpaceInvaders::Controllers
{
    class EnemyController
    {
    public:
        EnemyController(int rows, int columns,BulletController* buCo);
        void createEnemies();
        void enqueueEnemies(SpaceInvaders::Window::Window* win);
        void moveEnemies(double timePast);
        void removeEnemies();


        const vector<Enemy*> getEnemyVector() const;

        bool isGameOver() const;

        void setGameOver(bool gameOver);

        int getLevel() const;

        void setLevel(int level);

    private:
        vector<Enemy*> enemyVector;
        bool moveRight=true;
        int rows;
        int columns;
        bool gameOver = false;
        int level = 0;
        BulletController* buCo;
    };

}

#endif //GAME_ENEMYCONTROLLER_H
