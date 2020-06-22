//
// Created by Tijs Van Alphen on 20/06/2020.
//

#ifndef GAME_SDLICON_H
#define GAME_SDLICON_H

#include "../../Icon/Icon.h"
#include <SDL2/SDL_image.h>
#include "../Window/SDLWindow.h"

using namespace SpaceInvaders::Controllers;

namespace SDL
{
    class SDLIcon : public SpaceInvaders::Icon
    {
    public:
        SDLIcon(std::string path) : Icon(path)
        {};

        void loadIcon() override;

        void* dispIcon() override;

    private:
        SDL_Surface* IconSurface;
    };
}

#endif //GAME_SDLICON_H
