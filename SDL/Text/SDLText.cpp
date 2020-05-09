//
// Created by tijsv on 9/05/2020.
//
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_surface.h>
#include "../Window/SDLWindow.h"
#include "SDLText.h"

SDLText::SDLText(string text, int x, int y, int height, int width, void* font) : Text(text, x, y, height, width, font)
{
    this->createTexture();
    this->height=height;
    this->width =width;
}

void SDLText::createTexture()
{
    SDL_Color color = {255,255,255};
    auto* surface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(this->font),text.c_str(),color);

    auto* win = SpaceInvaders::Controllers::GameController::getInstance().getWindow();
    auto* winSDL = dynamic_cast<SDLWindow*>(win);

    this->texture = SDL_CreateTextureFromSurface(winSDL->getRenderer(),surface);
    this->width = surface->w * SCALE_X;
    this->height = surface->h * SCALE_Y;

    SDL_FreeSurface(surface);
}


