//
// Created by tijsv on 28/02/2020.
//

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <string>
#include <queue>
#include "../GameObject/GameObject.h"
#include "../Text/Text.h"
#include "../Icon/Icon.h"

namespace SpaceInvaders::Window
{
    class Window
    {

    public:
        virtual bool create() = 0; //boolean because we want to know is it is created correctly
        virtual void remove() = 0;

        virtual void draw() = 0;

        void setBackground(Sprite* background);

        void setIcon(Icon::Icon* icon);

        virtual bool pollEvents() = 0;

        void enqueueGO(SpaceInvaders::GameObjects::GameObject* gobject);
        void enqueueText(SpaceInvaders::Text::Text* txtObject);

    protected:
        std::queue<SpaceInvaders::GameObjects::GameObject*> goQueue;
        std::queue<SpaceInvaders::Text::Text*> textQueue;
        double timePast;
        double stopwatch;
        Sprite* background;
        Icon::Icon* icon;

    public:
        double getTimePast() const;

        double getStopwatch() const;

    };
}

#endif //GAME_WINDOW_H
