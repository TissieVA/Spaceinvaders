//
// Created by Tijs Van Alphen on 28/02/2020.
//

#include "SDLWindow.h"
#include "../../Sprite/Sprite.h"
#include "../Sprite/SDLSprite.h"
#include <string>
#include <cmath>

using namespace std;
using namespace SpaceInvaders::Controllers;

bool SDL::SDLWindow::create() {

    bool succes=true;
    string title = "Space Invaders";

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        succes= false;
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            succes = false;
        }
        else
        {
            renderer = SDL_CreateRenderer( window,-1, SDL_RENDERER_ACCELERATED);
            if ( renderer == nullptr)
                printf("Renderer couldn't be created, SDL_Error : %s \n",SDL_GetError());

            else {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init((imgFlags) & imgFlags)))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                }
                else
                {
                    if(TTF_Init() == -1)
                    {
                        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    }
                    else
                        screenSurface = SDL_GetWindowSurface(window);
                }
            }
        }
    }

    return succes; //We want 0 back if everything went normal
}

void SDL::SDLWindow::remove() {
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(text);
    texture= nullptr;

    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(image);
    SDL_FreeSurface(screenSurface);
    SDL_FreeSurface(textSurface);
    SDL_DestroyWindow(window); //destroy window
    window= nullptr;
    renderer= nullptr;
    IMG_Quit();
    SDL_Quit();
}

void SDL::SDLWindow::draw() {

    uint32_t ticks = SDL_GetTicks();


    SDL_SetWindowIcon(window, reinterpret_cast<SDL_Surface*>(icon->dispIcon())); //create desktop icon

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, reinterpret_cast<SDL_Texture*>(background->dispSprite()), nullptr, nullptr);


    while(!goQueue.empty()) //as long as objects are in the queue
    {
        auto* go=goQueue.front();
        SDL_Rect stretchRectangle; //make rectangle
        stretchRectangle.x = lround(go->getXpos()); //set x, y, width and height as gameobject
        stretchRectangle.y = lround(go->getYpos());
        stretchRectangle.w = go->getWidth();
        stretchRectangle.h = go->getHeight();
        SDL_Texture* texture = reinterpret_cast<SDL_Texture*>(go->getSprite()->dispSprite()); //get the sprite of go and make texture of it
        SDL_RenderCopy(renderer, texture, nullptr, &stretchRectangle); //set texture on renderer
        goQueue.pop();
    }

    while(!textQueue.empty()) //same for text elements
    {
        auto* text = textQueue.front();
        SDL_Rect stretchRectangle;
        stretchRectangle.x = lround(text->getXPos());
        stretchRectangle.y = lround(text->getYPos());
        stretchRectangle.w = text->getWidth();
        stretchRectangle.h = text->getHeight();
        SDL_Texture* texture = reinterpret_cast<SDL_Texture*>(text->display());
        SDL_RenderCopy(renderer, texture, nullptr, &stretchRectangle);
        textQueue.pop();
    }

    SDL_RenderPresent(renderer); //show renderer on screen

    uint32_t frameTicks = SDL_GetTicks() -ticks; //get time past ot render everything
    if(frameTicks < Time_120fps)
    {
        SDL_Delay(Time_120fps - frameTicks); //if time was to short delay
    }
    timePast= (SDL_GetTicks() - ticks)/1000.f;

    stopwatch =SDL_GetTicks();
}

bool SDL::SDLWindow::pollEvents() {

    SDL_Event ev;
    while( SDL_PollEvent(&ev) != 0)
    {
        if(ev.type == SDL_QUIT) //is window is closed
            return true;
        else if (ev.type == SDL_KEYDOWN) //if key pressed
        {
            if(ev.key.keysym.sym == SDL_KeyCode::SDLK_ESCAPE) //if escape button is pressed
                return true;
            KeyEvent(ev.key.keysym.sym, true); //go to keyEvent
        }
        else if (ev.type == SDL_KEYUP)
            KeyEvent(ev.key.keysym.sym,false);
    }
    return false;
}

void SDL::SDLWindow::KeyEvent(SDL_Keycode press, bool pressed) {

    SpaceInvaders::Events::Key key = SpaceInvaders::Events::Key::NOTHING;

    switch (press) { //check which is is been pressed and set to key

        case SDLK_LEFT :
            key = SpaceInvaders::Events::Key::LEFT;
            break;

        case SDLK_RIGHT :
            key = SpaceInvaders::Events::Key::RIGHT;
            break;

        case SDLK_SPACE :
            key = SpaceInvaders::Events::Key::SPACE;
            break;
    }

    if (pressed)
    {
        GameController::getInstance().getEventmanager()->KeyDown(key); //send key to eventmanager methods keydown
    }
    else
    {
        GameController::getInstance().getEventmanager()->KeyUp(key);  //send key to eventmanager methods keyup
    }
}