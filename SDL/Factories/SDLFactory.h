//
// Created by tijsv on 2/03/2020.
//

#ifndef GAME_SDLFACTORY_H
#define GAME_SDLFACTORY_H
#include <iostream>
#include "../../Factories/AFactory.h"
#include "../../SDL/Window/SDLWindow.h"


using namespace SpaceInvaders::Factories;

namespace SpaceInvaders::Factories {

    class SDLFactory : public AFactory {
    public:
        SpaceInvaders::Window::Window* makeWindow() override;
        Sprite* makeSprite(string path) override;
        Text::Text* makeText(string text, int x, int y, int fontSize, string font);
    };
}


#endif //GAME_SDLFACTORY_H
