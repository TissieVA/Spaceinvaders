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

void SDL::SDLSprite::loadSprite()
{
    SDL_Surface* loadedSurface= IMG_Load(path.c_str());

    if(loadedSurface== NULL)
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    else
    {
        auto* window = GameController::getInstance().getWindow();
        auto* sdlWindow = dynamic_cast<SDLWindow*>(window);

        texture = SDL_CreateTextureFromSurface(sdlWindow->getRenderer() , loadedSurface); //create texture from surface
        if (texture == nullptr)
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );

        SDL_FreeSurface(loadedSurface);
    }
}

void* SDL::SDLSprite::dispSprite()
{
    return texture;
}