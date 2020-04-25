//
// Created by tijsv on 28/02/2020.
//

#ifndef GAME_SDLWINDOW_H
#define GAME_SDLWINDOW_H
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "../../Window/Window.h"
#include <string>
#include "../../Constants.h"
#include "../../Events/EventObserver.h"
#include "../../Controllers/GameController.h"
#include "../../Constants.h"

class SDLWindow : public Window {
public:
    bool create() override ;
    void remove() override ;
    void draw() override ;
    bool pollEvents() override;
    void drawStretch() override;
    void loadSurface(std::string path);
    void loadTexture(std::string path);

    SDL_Renderer* getRenderer(){return renderer;}
    void KeyEvent(SDL_Keycode press, bool pressed);


private:
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;
    SDL_Surface* image = nullptr;
    SDL_Surface* PNGSurface = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* texture = nullptr;
};

#endif //GAME_SDLWINDOW_H