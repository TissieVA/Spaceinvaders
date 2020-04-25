//
// Created by tijsv on 2/03/2020.
//

#ifndef GAME_SDLFACTORY_H
#define GAME_SDLFACTORY_H
#include <iostream>
#include "../../Factories/AFactory.h"
#include "../../SDL/Window/SDLWindow.h"


using namespace Factories;

namespace Factories {

    class SDLFactory : public AFactory {
    public:
         Window* makeWindow() override;
         Sprite* makeSprite(string path) override;
    };
}


#endif //GAME_SDLFACTORY_H
