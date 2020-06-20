//
// Created by Tijs Van Alphen on 25/04/2020.
//

#include <cmath>
#include "MiscController.h"
using namespace SpaceInvaders::Controllers;

MiscController::MiscController(SpaceInvaders::Window::Window* win)
{
    this->win=win;
}

void MiscController::showHealth(int health) //sets the amounts of heart icons to enqueue
{
    heartsVector.clear();
    for (int i = 0; i < health+1; i++)
    {
        auto* heart = new Health(lround(SCREEN_WIDTH - i * 40 * SCALE_X), lround(10 * SCALE_Y),
                lround(30 * SCALE_X), lround(30 * SCALE_Y));
        heartsVector.push_back(heart);
    }

    for (auto* heart : heartsVector)
    {
        win->enqueueGO(heart);
    }
}

void MiscController::bonus(double timepast, SpaceInvaders::Window::Window* win) 
{
    if(rand() %BONUSCHANCE +1 ==1 && bonusVector.empty()) //1 in BONUSCHANCE of spawning and if there isn't another bonusship
    {
        auto* bonusship = new BonusShip(-lround(SCALE_X*BONUSSHIP_WIDTH),lround(40*SCALE_Y),lround(SCALE_X*BONUSSHIP_WIDTH),lround(SCALE_Y*BONUSSHIP_HEIGHT));

        bonusVector.push_back(bonusship);
        win->enqueueGO(bonusship);
    }

    for(int i=0; i<bonusVector.size() ;i++) //check if bonusship is still alive
    {
        auto* bonus = bonusVector.at(i);
        if(!bonus->isAlive())
            bonusVector.erase(bonusVector.begin()+i);  //removes dead enemies from vector
    }

    for (auto* bonus:bonusVector)
    {
        win->enqueueGO(bonus);
        bonus->update(win->getTimePast());
    }
    moveBonus(timepast);
}

void MiscController::moveBonus(double timepast)
{

    for(auto* bonus : bonusVector)
    {
        if(bonus->getXpos() >= SCREEN_WIDTH)
            bonus->setAlive(0);
        bonus->setXDirection(1);
        bonus->update(timepast);
    }
}

const vector<BonusShip*> & MiscController::getBonusVector() const
{
return bonusVector;
}

void MiscController::removeBonus()
{
    bonusVector.clear();
}

MiscController::~MiscController()
{
    bonusVector.clear();
    heartsVector.clear();
}




