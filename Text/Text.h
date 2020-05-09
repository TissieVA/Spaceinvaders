//
// Created by tijsv on 9/05/2020.
//

#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <string>
using namespace std;
namespace SpaceInvaders::Text
{
    class Text
    {
    public:
        Text(string text, int x, int y, int heigth, int width, void* font);

        void setText(string text);

        virtual void createTexture() =0;

    protected:
        string text;
        void* font;
        int height;
        int width;
    };
}

#endif //GAME_TEXT_H
