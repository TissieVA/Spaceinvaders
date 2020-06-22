//
// Created by Tijs Van Alphen on 9/05/2020.
//

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include "../Window/SDLWindow.h"
#include "SDLText.h"

SDL::SDLText::SDLText(string text, int x, int y, int fontSize, string font) : Text(text, x, y, fontSize, font)
{
                               // Font path,   Char Size
    this->font = TTF_OpenFont(font.c_str(), fontSize);
    this->createTexture();
}

void SDL::SDLText::createTexture()
{
    SDL_Color color = {255,255,255}; //white color text
    auto* surface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(this->font),text.c_str(), color); //create surface from ttf

    auto* win = SpaceInvaders::Controllers::GameController::getInstance().getWindow();
    auto* winSDL = dynamic_cast<SDLWindow*>(win);

    this->texture = SDL_CreateTextureFromSurface(winSDL->getRenderer(), surface); //create texture from surface
    this->width = surface->w * SCALE_X;
    this->height = surface->h * SCALE_Y;

    SDL_FreeSurface(surface);
}

void* SDL::SDLText::display()
{
    return this->texture;
}

SDL::SDLText::~SDLText()
{
    SDL_DestroyTexture(this->texture);
    TTF_CloseFont(reinterpret_cast<TTF_Font*>(this->font));
}


