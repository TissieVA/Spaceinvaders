//
// Created by Tijs Van Alphen on 24/02/2020.
//

#ifndef GAME_AFACTORY_H
#define GAME_AFACTORY_H

#include "../Window/Window.h"

#include <string>

using namespace std;

namespace SpaceInvaders::Factories {

    class AFactory {
    public:
        virtual SpaceInvaders::Window* makeWindow() =0;
        virtual Sprite* makeSprite(string path)=0;
        virtual Text* makeText(string text, int x, int y, int fontSize, string font) = 0;
        virtual Icon* makeIcon(string path)=0;
    };
}


#endif //GAME_AFACTORY_H
