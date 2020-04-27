//
// Created by tijsv on 9/04/2020.
//

#include <cmath>
#include "EnemyController.h"
#include "../GameObject/Enemy.h"

Controllers::EnemyController::EnemyController(int rows, int columns, BulletController* buCo)
{
    this->rows=rows;
    this->columns=columns;
    this->buCo=buCo;
    createEnemies();
}

void Controllers::EnemyController::createEnemies()
{
    for (int j = 0; j < rows; ++j) {

        for (int i = 0; i < columns; ++i) {
            auto* enem = new Enemy(lround(SCALE_X * (20 + (50 + 40) * i)), lround(50*SCALE_Y+ SCALE_Y * (10+(100*j))), lround(SCALE_X*200/2.5),
                                   lround(SCALE_Y*185/2.5));
            enemyVector.push_back(enem);
        }
    }
}

void Controllers::EnemyController::enqueueEnemies(Window* win)
{
    for(int i=0; i<enemyVector.size() ;i++)
    {
        auto* enem = enemyVector.at(i);
        if(!enem->isAlive())
            enemyVector.erase(enemyVector.begin()+i);  //removes dead enemies from vector
    }

    for (auto* enem:enemyVector)
    {
        win->enqueueGO(enem);
        enem->update(win->getTimePast());
    }
}

void EnemyController::moveEnemies(double timePast)
{
    bool previousMove = moveRight;
    bool hitBottom = false;
    for (auto* enem: enemyVector)
    {
        if (enem->getXpos() <= 0)
            moveRight=true;
        else if (enem->getXpos()+enem->getWidth() >= SCREEN_WIDTH)
            moveRight= false;

        if(enem->getYpos()+enem->getHeight()>SCREEN_HEIGHT-150*SCALE_Y)
            hitBottom=true;

        if((rand() %CHANCE +1) ==1) //chance of enemy to shoot
        {
            buCo->addBullet(lround(enem->getXpos()+enem->getWidth()/2),enem->getYpos()+enem->getHeight(),1,true);
        }

    }

    if (moveRight && previousMove == moveRight) //Moving to right and didn't hit border
    {
        for (auto* enem: enemyVector)
        {
            enem->setXDirection(1);
            enem->setYDirection(0);
            enem->update(timePast);
        }
    } else if (moveRight && previousMove != moveRight) //Moving right but we were moving left (hit right border)
    {
        for (auto* enem: enemyVector)
        {
            enem->setXDirection(1);
            enem->setYDirection(1);
            enem->update(timePast);
        }
    } else if (!moveRight && previousMove == moveRight) //Moving left and didn't hit border
    {
        for (auto* enem: enemyVector)
        {
            enem->setXDirection(-1);
            enem->setYDirection(0);
            enem->update(timePast);
        }
    } else if (!moveRight && previousMove != moveRight) // moving to left but we were moving to right (hit left border)
    {
        for (auto* enem: enemyVector)
        {
            enem->setXDirection(-1);
            enem->setYDirection(1);
            enem->update(timePast);
        }
    } else
        printf("wrong movement: check EnemyController, move enemies");

    if (hitBottom || enemyVector.empty())
    {
        removeEnemies();
        createEnemies();
    }

}

void Controllers::EnemyController::removeEnemies()
{
    for (auto* enem: enemyVector)
    {
        enemyVector.clear();
    }
}

const vector<Enemy*> &EnemyController::getEnemyVector() const
{
    return enemyVector;
}


