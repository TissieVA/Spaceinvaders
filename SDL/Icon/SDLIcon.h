//
// Created by tijsv on 20/06/2020.
//

#ifndef GAME_SDLICON_H
#define GAME_SDLICON_H

#include "../../Icon/Icon.h"
#include <SDL2/SDL_image.h>
#include "../Window/SDLWindow.h"

using namespace SpaceInvaders::Icon;
using namespace SpaceInvaders::Controllers;

class SDLIcon : public Icon
{
public:
    SDLIcon(std::string path): Icon(path){};

    void loadIcon() override;
    void* dispIcon() override;

private:
    SDL_Surface* IconSurface;
};


#endif //GAME_SDLICON_H
