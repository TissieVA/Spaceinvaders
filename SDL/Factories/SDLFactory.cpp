//
// Created by tijsv on 2/03/2020.
//

#include "SDLFactory.h"
#include "../Sprite/SDLSprite.h"

using namespace std;


SpaceInvaders::Window::Window* SDLFactory::makeWindow() {

    return new SDLWindow ;
}

Sprite* SDLFactory::makeSprite(string path)
{
    auto* sprite = new SDLSprite(path);
    sprite->loadSprite();
    return sprite;
}
