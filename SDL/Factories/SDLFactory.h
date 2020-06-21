//
// Created by Tijs Van Alphen on 2/03/2020.
//

#ifndef GAME_SDLFACTORY_H
#define GAME_SDLFACTORY_H
#include <iostream>
#include "../../Factories/AFactory.h"
#include "../../SDL/Window/SDLWindow.h"


using namespace SpaceInvaders::Factories;

namespace SDL::Factories {

    class SDLFactory : public AFactory {
    public:
        SpaceInvaders::Window* makeWindow() override;
        SpaceInvaders::Sprite* makeSprite(string path) override;
        SpaceInvaders::Text* makeText(string text, int x, int y, int fontSize, string font);
        SpaceInvaders::Icon* makeIcon(string path) override;
    };
}


#endif //GAME_SDLFACTORY_H
