//
// Created by Tijs Van Alphen on 25/04/2020.
//

#ifndef GAME_MISCCONTROLLER_H
#define GAME_MISCCONTROLLER_H


#include "../Window/Window.h"
#include "../GameObject/Health.h"
#include "../GameObject/BonusShip.h"

namespace Controllers

{
    class MiscController
    {
    public:
        MiscController(Window* win);
        void showHealth(int health);
        void bonus(double timepast,Window* win);
        void moveBonus(double timepast);

        const vector<BonusShip*> & getBonusVector() const;

    private:
        Window* win;
        vector<Health*> hearts;
        bool moveRight =true;
        vector<BonusShip*> bonusVector;

    };

}


#endif //GAME_MISCCONTROLLER_H
