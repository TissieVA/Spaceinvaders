//
// Created by Tijs Van Alphen on 25/04/2020.
//

#include <cmath>
#include "MiscController.h"


Controllers::MiscController::MiscController(Window* win)
{
    this->win=win;
}

void Controllers::MiscController::showHealth(int health)
{
    hearts.clear();
    for (int i = 0; i < health+1; i++)
    {
        auto* heart = new Health(lround(SCREEN_WIDTH - i * 40 * SCALE_X), lround(10 * SCALE_Y),
                lround(30 * SCALE_X), lround(30 * SCALE_Y));
        hearts.push_back(heart);
    }

    for (auto* heart : hearts)
    {
        win->enqueueGO(heart);
    }
}

void MiscController::bonus(double timepast, Window* win)
{
    if(rand() %1000 +1 ==1 && bonusvector.empty()) //1 in 10000 chance of spawning adn if there isn't another bonusship
    {
        auto* bonusship = new BonusShip(-lround(SCALE_X*200),lround(100*SCALE_Y),lround(SCALE_X*200),lround(SCALE_Y*100));

        bonusvector.push_back(bonusship);
        win->enqueueGO(bonusship);
    }

    for(int i=0; i<bonusvector.size() ;i++)
    {
        auto* bonus = bonusvector.at(i);
        if(!bonus->isAlive())
            bonusvector.erase(bonusvector.begin()+i);  //removes dead enemies from vector
    }

    for (auto* bonus:bonusvector)
    {
        win->enqueueGO(bonus);
        bonus->update(win->getTimePast());
    }
    moveBonus(timepast);
}

void MiscController::moveBonus(double timepast)
{

    for(auto* bonus : bonusvector)
    {
        if(bonus->getXpos() >= SCREEN_WIDTH)
            bonus->setAlive(0);
        bonus->setXDirection(1);
        bonus->update(timepast);
    }
}



