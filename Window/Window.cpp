//
// Created by tijsv on 28/02/2020.
//

#include "Window.h"

using namespace SpaceInvaders::GameObjects;
using namespace SpaceInvaders::Window;
using namespace SpaceInvaders::Icon;

void Window::enqueueGO(GameObject* gobject)
{
    goQueue.push(gobject);
}

void Window::enqueueText(SpaceInvaders::Text::Text* txtObject)
{
    this->textQueue.push(txtObject);
}

double Window::getTimePast() const
{
    return timePast;
}

void Window::setBackground(Sprite* background)
{
   this->background = background;
}

void Window::setIcon(Icon::Icon* icon)
{
    this->icon= icon;
}



