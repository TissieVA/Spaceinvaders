//
// Created by tijsv on 28/02/2020.
//

#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <string>
#include <queue>
#include "../GameObject/GameObject.h"

namespace SpaceInvaders::Window
{
    class Window
    {

    public:
        virtual bool create() = 0; //boolean because we want to know is it is created correctly
        virtual void remove() = 0;

        virtual void draw() = 0;

        virtual void drawStretch() = 0;

        virtual void loadSurface(std::string path) = 0;

        virtual void loadTexture(std::string path) = 0;

        void setBackground(Sprite* background);

        void setIcon(Sprite* icon);

        virtual bool pollEvents() = 0;

        void enqueueGO(SpaceInvaders::GameObjects::GameObject* gobject);

    protected:
        std::queue<SpaceInvaders::GameObjects::GameObject*> goQueue;
        double timePast;
        Sprite* background;
        Sprite* icon;
    public:
        double getTimePast() const;

    };
}

#endif //GAME_WINDOW_H
