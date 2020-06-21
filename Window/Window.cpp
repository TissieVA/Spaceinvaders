//
// Created by Tijs Van Alphen on 28/02/2020.
//

#include "Window.h"

using namespace SpaceInvaders::GameObjects;

void SpaceInvaders::Window::enqueueGO(GameObject* gobject) //places gameobject in goQueue
{
    goQueue.push(gobject);
}

void SpaceInvaders::Window::enqueueText(SpaceInvaders::Text* txtObject) //places text in textQueue
{
    this->textQueue.push(txtObject);
}

double SpaceInvaders::Window::getTimePast() const
{
    return timePast;
}

void SpaceInvaders::Window::setBackground(Sprite* background)
{
   this->background = background;
}

void SpaceInvaders::Window::setIcon(Icon* icon)
{
    this->icon= icon;
}

double SpaceInvaders::Window::getStopwatch() const
{
    return stopwatch;
}



