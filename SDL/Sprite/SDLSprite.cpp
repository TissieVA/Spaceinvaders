//
// Created by Tijs Van Alphen on 23/03/2020.
//

#include "SDLSprite.h"
#include "../../Controllers/GameController.h"
#include "../Window/SDLWindow.h"
#include <stdio.h>
#include <string>

using namespace std;
using namespace SpaceInvaders::Controllers;

void SDLSprite::loadSprite()
{
    SDL_Surface* loadedSurface= IMG_Load(path.c_str());

    if(loadedSurface== NULL)
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    else
    {
        auto* window = GameController::getInstance().getWindow();
        auto* sdlWindow = dynamic_cast<SDLWindow*>(window);


        SDL_SetColorKey(loadedSurface,SDL_TRUE, SDL_MapRGB(loadedSurface->format,0, 0xFF,0xFF));

        texture = SDL_CreateTextureFromSurface(sdlWindow->getRenderer() , loadedSurface);
        if (texture == nullptr)
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        else
            int w = loadedSurface->w;

        SDL_FreeSurface(loadedSurface);
    }
}

void* SDLSprite::dispSprite()
{
    return texture;
}