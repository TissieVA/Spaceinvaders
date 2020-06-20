//
// Created by tijsv on 20/06/2020.
//

#include <SDL2/SDL_surface.h>
#include "SDLIcon.h"
#include "../Window/SDLWindow.h"

void SDLIcon::loadIcon()
{
    IconSurface = IMG_Load(path.c_str());
    if(IconSurface== NULL)
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    else
    {
        auto* window = GameController::getInstance().getWindow();
        auto* sdlWindow = dynamic_cast<SDLWindow*>(window);

        SDL_SetColorKey(IconSurface,SDL_TRUE, SDL_MapRGB(IconSurface->format,0, 0xFF,0xFF));

    }
}

void* SDLIcon::dispIcon()
{
    return IconSurface;
}

