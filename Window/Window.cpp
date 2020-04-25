//
// Created by tijsv on 28/02/2020.
//

#include "Window.h"

void Window::enqueueGO(GameObject* gobject)
{
    goQueue.push(gobject);
}

double Window::getTimePast() const {
    return timePast;
}

void Window::setBackground(Sprite* background)
{
    Window::background = background;
}
