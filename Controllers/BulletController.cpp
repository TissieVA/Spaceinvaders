//
// Created by Tijs Van Alphen on 14/04/2020.
//

#include "BulletController.h"
#include <math.h>
using namespace std;
BulletController::BulletController(Player* player)
{
    this->player=player;
}

void Controllers::BulletController::addBullet(int xPos, int yPos,int direction, bool fromEnemy)
{
    auto* bullet = new Bullet(xPos,yPos-lround(BULLET_HEIGHT*SCALE_Y),lround(BULLET_WIDTH*SCALE_X),lround(BULLET_HEIGHT*SCALE_Y),direction,fromEnemy);
    bulletVector.push_back(bullet);
}

void Controllers::BulletController::enqueueBullets(Window* win)
{
    for (int i=0; i< bulletVector.size(); i++)
    {
        auto* bullet =bulletVector.at(i);
        if(!bullet->isAlive())
            bulletVector.erase(bulletVector.begin()+i); //remove bullet that had hit something
    }

    for (auto* bullet :bulletVector)
    {
        win->enqueueGO(bullet);
    }
}

void Controllers::BulletController::moveBullets(double timePast, vector<Enemy*> enemyVector,vector<BonusShip*> bonusVector)
{
    for (auto* bullet: bulletVector)
    {
        if(bullet->getDirection() < 0) //bullet coming from player
        {
            for (auto* enem: enemyVector) //check for every enemy
            {

                if (bullet->getXpos() + (bullet->getWidth() / 2) > enem->getXpos() &&
                    bullet->getXpos() + (bullet->getWidth() / 2) < enem->getXpos() +
                                                                   enem->getWidth()) //if middle of xpos of bullet is more to right than left side of enemy and more to the left than the right side of the enemy
                {
                    if (bullet->getYpos() > enem->getYpos() && bullet->getYpos() < enem->getYpos() + enem->getHeight())
                    {
                        //hit with an enemy

                        enem->setAlive(false);
                        bullet->setAlive(false);
                        score = score + (SCREEN_HEIGHT-enem->getYpos());
                        break; //enemy hit
                    }
                }
            }
            for (auto* bonus : bonusVector)
            {
                if (bullet->getXpos() + (bullet->getWidth() / 2) > bonus->getXpos() &&
                    bullet->getXpos() + (bullet->getWidth() / 2) < bonus->getXpos() +
                                                                   bonus->getWidth()) //if middle of xpos of bullet is more to right than left side of enemy and more to the left than the right side of the enemy
                {
                    if (bullet->getYpos() > bonus->getYpos() && bullet->getYpos() < bonus->getYpos() + bonus->getHeight())
                    {
                        //hit with an enemy

                        bonus->setAlive(false);
                        bullet->setAlive(false);
                        score = score + (SCREEN_HEIGHT-bonus->getYpos());
                        player->setHealth(player->getHealth()+1);  //if bonusship is hit, get extra live
                        break; //enemy hit
                    }
                }
            }
        }
        else if (bullet->getDirection()>0) //coming from enemy
        {
            if ((bullet->getYpos() + bullet->getHeight() >= player->getYpos()))
            {
                if (lround(bullet->getXpos() + bullet->getWidth() / 2) >= player->getXpos()
                    && lround(bullet->getXpos() + bullet->getWidth() / 2) <=
                       player->getXpos() + player->getWidth()) //if bullet is inside player
                {
                    player->setHealth(player->getHealth() - 1); //reduce health with one
                    bullet->setAlive(false);
                }
            }

        }

        if(bullet->getYpos() <= 0 || bullet->getYpos()+bullet->getHeight()>= SCREEN_HEIGHT)
            bullet->setAlive(false);

        bullet->update(timePast);


    }
}

int BulletController::getScore() const
{
    return score;
}

