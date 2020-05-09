//
// Created by tijsv on 28/02/2020.
//

#include "SDLWindow.h"
#include "../../Sprite/Sprite.h"
#include "../Sprite/SDLSprite.h"
#include <string>
#include <cmath>

using namespace std;
using namespace SpaceInvaders::Controllers;

bool SDLWindow::create() {

    bool succes=true;
    string title = "SDL test";

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
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                else
                    screenSurface = SDL_GetWindowSurface(window);
            }
        }
    }

    return succes; //We want 0 back if everything went normal
}

void SDLWindow::remove() {
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

void SDLWindow::draw() {

    uint32_t ticks = SDL_GetTicks();


   //SDL_SetWindowIcon(window, reinterpret_cast<SDL_Surface*>(icon));

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, reinterpret_cast<SDL_Texture*>(background->dispSprite()), nullptr, nullptr);



    while(!goQueue.empty())
    {
        auto* go=goQueue.front();
        SDL_Rect stretchRectangle;
        stretchRectangle.x = lround(go->getXpos());
        stretchRectangle.y = lround(go->getYpos());
        stretchRectangle.w = go->getWidth();
        stretchRectangle.h = go->getHeight();
        SDL_Texture* texture = reinterpret_cast<SDL_Texture*>(go->getSprite()->dispSprite());
        SDL_RenderCopy(renderer,texture, nullptr, &stretchRectangle);
        goQueue.pop();
    }

    SDL_RenderPresent(renderer);

    uint32_t frameTicks = SDL_GetTicks() -ticks;
    if(frameTicks < Time_120fps)
    {
        SDL_Delay(Time_120fps - frameTicks);
    }
    timePast= (SDL_GetTicks() - ticks)/1000.f;
}

bool SDLWindow::pollEvents() {

    SDL_Event ev;
    while( SDL_PollEvent(&ev) != 0)
    {
        if(ev.type == SDL_QUIT)
            return true;
        else if (ev.type == SDL_KEYDOWN)
        {
            if(ev.key.keysym.sym == SDL_KeyCode::SDLK_ESCAPE)
                return true;
            KeyEvent(ev.key.keysym.sym, true);
        }
        else if (ev.type == SDL_KEYUP)
            KeyEvent(ev.key.keysym.sym,false);
    }
    return false;
}

void SDLWindow::loadSurface(string path) {

    SDL_Surface* optimizedSurface= nullptr;

    SDL_Surface* loadedSurface= IMG_Load(path.c_str());

    if(loadedSurface== NULL)
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    else
    {
        optimizedSurface = SDL_ConvertSurface( loadedSurface, screenSurface -> format, 0);
        if (optimizedSurface == nullptr)
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );

        SDL_FreeSurface(loadedSurface);
    }

    image= optimizedSurface;
}

void SDLWindow::loadTexture(string path) {

    // Sprite klasse
    //  -> Texture
    //  -> Dimensies

    //Sprite s = new SDLSprite(path);
    // -> surface laden
    // -> texture van maken
    // -> void* giveTexture()

    SDL_Texture* newTexture= nullptr;

    SDL_Surface* loadedSurface= IMG_Load(path.c_str());

    if(loadedSurface== NULL)
        printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    else
    {
        SDL_SetColorKey(loadedSurface,SDL_TRUE, SDL_MapRGB(loadedSurface->format,0, 0xFF,0xFF));

        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface);
        if (newTexture == nullptr)
            printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        else
            int w = loadedSurface->w;

        SDL_FreeSurface(loadedSurface);
    }

    texture = newTexture ;
}

void SDLWindow::drawStretch(){

    if (image == nullptr)
        printf( "Failed to load stretching image!\n" );
    SDL_Rect stretchRect;
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;
    SDL_BlitScaled( image, NULL, screenSurface, &stretchRect );
    SDL_UpdateWindowSurface( window );
    }

void SDLWindow::KeyEvent(SDL_Keycode press, bool pressed) {

    SpaceInvaders::Events::Key key = SpaceInvaders::Events::Key::NOTHING;

            switch (press) {

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
                GameController::getInstance().getEventmanager()->KeyDown(key);
            }
            else
            {
                GameController::getInstance().getEventmanager()->KeyUp(key);
            }
}

void SDLWindow::loadFromRenderedText(string textString, SDL_Color color)
{
    //Get rid of preexisting texture
    //free();

    //Render text surface1

   //textSurface = TTF_RenderText_Solid( font, textString.c_str(), color );
   /*
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        text = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( text == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }


        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }*/
}







