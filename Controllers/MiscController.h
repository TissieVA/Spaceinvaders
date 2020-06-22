//
// Created by Tijs Van Alphen on 25/04/2020.
//

#ifndef GAME_MISCCONTROLLER_H
#define GAME_MISCCONTROLLER_H


#include "../Window/Window.h"
#include "../GameObject/Health.h"
#include "../GameObject/BonusShip.h"
#include "../GameObject/Cover.h"


namespace SpaceInvaders::Controllers

{
    class MiscController
    {
    public:
        MiscController(SpaceInvaders::Window* win);

        virtual ~MiscController();

        void showHealth(int health);
        void bonus(double timepast,SpaceInvaders::Window* win);
        void moveBonus(double timepast);
        void removeBonus();
        string dispTime(double stopwatch);
        void createCover();
        void enqueueCover(SpaceInvaders::Window* win);

        const vector<BonusShip*> &getBonusVector() const;

        const vector<Cover*> &getCoverVector() const;


    private:
        SpaceInvaders::Window* win;
        vector<Health*> heartsVector;
        bool moveRight =true;
        vector<BonusShip*> bonusVector;
        vector<Cover*> coverVector;
    };

}


#endif //GAME_MISCCONTROLLER_H
