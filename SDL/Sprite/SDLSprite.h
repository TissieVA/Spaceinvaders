//
// Created by Tijs Van Alphen on 23/03/2020.
//

#ifndef GAME_SDLSPRITE_H
#define GAME_SDLSPRITE_H

#include <stdio.h>
#include <SDL2/SDL_render.h>
#include "../../Sprite/Sprite.h"
#include <SDL2/SDL_image.h>
#include <string>
using namespace std;

namespace SDL
{
    class SDLSprite : public SpaceInvaders::Sprite
    {
    public:
        SDLSprite(string path) : Sprite(path)
        {};

        void loadSprite() override;

        void* dispSprite() override;

    private:
        SDL_Texture* texture;
    };
}

#endif //GAME_SDLSPRITE_H
