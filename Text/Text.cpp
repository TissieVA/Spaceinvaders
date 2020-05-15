//
// Created by tijsv on 9/05/2020.
//

#include "Text.h"

SpaceInvaders::Text::Text::Text(string text, int x, int y, int fontSize, string font)
{
    this->text = text;
    this->fontSize = fontSize;
}

void SpaceInvaders::Text::Text::setText(string text)
{
    this->text = text;
    this->createTexture();
}

int SpaceInvaders::Text::Text::getHeight() const
{
    return height;
}

void SpaceInvaders::Text::Text::setHeight(int height)
{
    Text::height = height;
}

int SpaceInvaders::Text::Text::getWidth() const
{
    return width;
}

void SpaceInvaders::Text::Text::setWidth(int width)
{
    Text::width = width;
}

double SpaceInvaders::Text::Text::getXPos() const
{
    return xPos;
}

void SpaceInvaders::Text::Text::setXPos(double xPos)
{
    Text::xPos = xPos;
}

double SpaceInvaders::Text::Text::getYPos() const
{
    return yPos;
}

void SpaceInvaders::Text::Text::setYPos(double yPos)
{
    Text::yPos = yPos;
}

int SpaceInvaders::Text::Text::getFontSize() const
{
    return fontSize;
}

void SpaceInvaders::Text::Text::setFontSize(int fontSize)
{
    Text::fontSize = fontSize;
}
