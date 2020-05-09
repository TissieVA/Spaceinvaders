//
// Created by tijsv on 9/05/2020.
//

#include "Text.h"

SpaceInvaders::Text::Text::Text(string text, int x, int y, int height,int width, void* font)
{
    this->text = text;
    this->font = font;
    this->height=height;
    this->width=width;
}

void SpaceInvaders::Text::Text::setText(string text)
{
    this->text = text;
    this->createTexture();
}
