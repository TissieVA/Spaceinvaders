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

}

void* SDLIcon::dispIcon()
{
    return IconSurface;
}

