//
// Created by Tijs Van Alphen on 25/04/2020.
//

#ifndef GAME_MISCCONTROLLER_H
#define GAME_MISCCONTROLLER_H


#include "../Window/Window.h"
#include "../GameObject/Health.h"

namespace Controllers

{
    class MiscController
    {
    public:
        MiscController(Window* win);
        void showHealth(int health);

    private:
        Window* win;
        vector<Health*> hearts;
    };

}


#endif //GAME_MISCCONTROLLER_H
