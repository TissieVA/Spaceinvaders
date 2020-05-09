 //
// Created by Tijs Van Alphen on 23/03/2020.
//

#include "GameObject.h"
using namespace SpaceInvaders::GameObjects;

GameObject::GameObject(double xpos, double ypos, int width, int height)
{
    this->xPos=xpos;
    this->yPos=ypos;
    this->height=height;
    this->width=width;
}

Sprite *GameObject::getSprite() const {
    return sprite;
}

double GameObject::getXpos() const {
    return xPos;
}

double GameObject::getYpos() const {
    return yPos;
}

int GameObject::getHeight() const {
    return height;
}

int GameObject::getWidth() const {
    return width;
}

void GameObject::setXpos(double xpos) {
    xPos = xpos;
}

void GameObject::setYpos(double ypos) {
    yPos = ypos;
}

void GameObject::setHeight(int height) {
    GameObject::height = height;
}

void GameObject::setWidth(int width) {
    GameObject::width = width;
}

void GameObject::move(double x_direction,double y_direction) {

    if (xPos + width + x_direction > SCREEN_WIDTH)
        xPos = SCREEN_WIDTH - width;

    else if (xPos + x_direction < 0)
    {
        xPos = 0;
    }
    else
    {
        xPos += x_direction;
    }

    if (yPos + height + y_direction > SCREEN_HEIGHT)
        yPos = SCREEN_HEIGHT - height;

    else if (yPos + y_direction <0)
    {
        yPos = 0;
    }
    else
    {
        yPos += y_direction;
    }
}
