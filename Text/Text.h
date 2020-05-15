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
        Text(string text, int x, int y, int fontSize, string font);
        virtual ~Text() = default;

        void setText(string text);

        virtual void createTexture() =0;
        virtual void* display() = 0;

        int getHeight() const;
        void setHeight(int height);
        int getWidth() const;
        void setWidth(int width);

        double getXPos() const;
        void setXPos(double xPos);
        double getYPos() const;
        void setYPos(double yPos);

        int getFontSize() const;



    protected:
        string text;
        void* font;
        int fontSize;
        int height;
        int width;
        double xPos, yPos;
    };
}

#endif //GAME_TEXT_H
