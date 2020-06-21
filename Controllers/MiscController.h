//
// Created by Tijs Van Alphen on 25/04/2020.
//

#ifndef GAME_MISCCONTROLLER_H
#define GAME_MISCCONTROLLER_H


#include "../Window/Window.h"
#include "../GameObject/Health.h"
#include "../GameObject/BonusShip.h"
using namespace SpaceInvaders::Window;

namespace SpaceInvaders::Controllers

{
    class MiscController
    {
    public:
        MiscController(SpaceInvaders::Window::Window* win);

        virtual ~MiscController();

        void showHealth(int health);
        void bonus(double timepast,SpaceInvaders::Window::Window* win);
        void moveBonus(double timepast);
        void removeBonus();
        string dispTime(double stopwatch);

        const vector<BonusShip*> & getBonusVector() const;

    private:
        SpaceInvaders::Window::Window* win;
        vector<Health*> heartsVector;
        bool moveRight =true;
        vector<BonusShip*> bonusVector;

    };

}


#endif //GAME_MISCCONTROLLER_H
