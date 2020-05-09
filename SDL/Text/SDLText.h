//
// Created by tijsv on 9/05/2020.
//

#ifndef GAME_SDLTEXT_H
#define GAME_SDLTEXT_H


#include "../../Text/Text.h"
using namespace std;

class SDLText : public SpaceInvaders::Text::Text
{
public:
    SDLText(string text, int x, int y, int height, int width, void* font);

private:
    void createTexture() override ;
    SDL_Texture* texture;
};


#endif //GAME_SDLTEXT_H
