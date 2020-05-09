//
// Created by tijsv on 24/02/2020.
//

#ifndef GAME_AFACTORY_H
#define GAME_AFACTORY_H

#include "../Window/Window.h"

#include <string>

using namespace std;

namespace SpaceInvaders::Factories {

    class AFactory {
    public:
        //virtual PlayerShip* CreatePS()=0;
        virtual SpaceInvaders::Window::Window* makeWindow() =0;
        virtual Sprite* makeSprite(string path)=0;
    };
}


#endif //GAME_AFACTORY_H
