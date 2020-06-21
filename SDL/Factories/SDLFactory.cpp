//
// Created by Tijs Van Alphen on 2/03/2020.
//

#include "SDLFactory.h"
#include "../Sprite/SDLSprite.h"
#include "../Text/SDLText.h"
#include "../Icon/SDLIcon.h"

using namespace std;


SpaceInvaders::Window* SDL::Factories::SDLFactory::makeWindow() {

    return new SDLWindow ;
}

SpaceInvaders::Sprite* SDL::Factories::SDLFactory::makeSprite(string path)
{
    auto* sprite = new SDLSprite(path);
    sprite->loadSprite();
    return sprite;
}

SpaceInvaders::Text* SDL::Factories::SDLFactory::makeText(string text, int x, int y, int fontSize, string font)
{
    return new SDLText(text, x, y, fontSize, font);
}

SpaceInvaders::Icon* SDL::Factories::SDLFactory::makeIcon(string path)
{
    auto* icon = new SDLIcon(path);
    icon->loadIcon();
    return icon;
}

