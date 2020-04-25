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

