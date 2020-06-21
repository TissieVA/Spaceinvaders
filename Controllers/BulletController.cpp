//
// Created by Tijs Van Alphen on 14/04/2020.
//

#include "BulletController.h"
#include <math.h>
using namespace std;
using namespace SpaceInvaders::Controllers;

BulletController::BulletController(Player* player)
{
    this->player=player;
}

void BulletController::addBullet(int xPos, int yPos,int direction, bool fromEnemy)
{
    if(fromEnemy)
    {
        auto* bullet = new Bullet(xPos, yPos + lround(ENEMY_BULLET_HEIGHT * SCALE_Y) ,
                lround(ENEMY_BULLET_WIDTH * SCALE_X), lround(ENEMY_BULLET_HEIGHT * SCALE_Y), direction, fromEnemy);
        bulletVector.push_back(bullet);
    }
    else
    {
        auto* bullet = new Bullet(xPos, yPos - lround(PLAYER_BULLET_HEIGHT * SCALE_Y),
                lround(PLAYER_BULLET_WIDTH * SCALE_X), lround(PLAYER_BULLET_HEIGHT * SCALE_Y), direction, fromEnemy);
        bulletVector.push_back(bullet);
    }

}

void BulletController::enqueueBullets(SpaceInvaders::Window::Window* win)
{
    for (int i=0; i< bulletVector.size(); i++) //check which bullets in vector are alive and remove the ones that aren't
    {
        auto* bullet =bulletVector.at(i);
        if(!bullet->isAlive())
            bulletVector.erase(bulletVector.begin()+i); //remove bullet that has hit something
    }

    for (auto* bullet :bulletVector) //enqueue the remaining bullets
    {
        win->enqueueGO(bullet);
    }
}

void BulletController::moveBullets(double timePast, vector<Enemy*> enemyVector,vector<BonusShip*> bonusVector)
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

                        enem->setAlive(false); //set enemy to dead
                        score += lround((SCREEN_HEIGHT - enem->getYpos())/5); //higher score if enemy is at top of screen
                        bullet->setAlive(false); //set bullet to dead

                        break; //enemy hit
                    }
                }
            }
            for (auto* bonus : bonusVector) //check if bonusship is hit
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
                        score += 1000;
                        if(player->getHealth()<MAX_HEALTH)
                            player->setHealth(player->getHealth()+1);  //if bonusship is hit, get extra live
                        break; //enemy hit
                    }
                }
            }
        }
        else if (bullet->getDirection()>0) //coming from enemy
        {
            if ((bullet->getYpos() + bullet->getHeight() >= player->getYpos())) //if tip of bullet is lower then top of player (inverse for values)
            {
                if (lround(bullet->getXpos() + bullet->getWidth() / 2) >= player->getXpos()
                    && lround(bullet->getXpos() + bullet->getWidth() / 2) <=
                       player->getXpos() + player->getWidth()) //if bullet is inside player
                {
                    player->setHealth(player->getHealth() - 1); //reduce health with one
                    bullet->setAlive(false); //kill bullet
                }
            }

        }

        if(bullet->getYpos() <= 0 || bullet->getYpos()+bullet->getHeight()>= SCREEN_HEIGHT) //kill bullet if it has hit the bottom or top
            bullet->setAlive(false);

        bullet->update(timePast); //move bullet


    }
}

void BulletController::removeBullets()
{
    bulletVector.clear();
}

int BulletController::getScore() const
{
    return score;
}

void BulletController::setScore(int score)
{
    BulletController::score = score;
}

BulletController::~BulletController()
{
    bulletVector.clear();

}






