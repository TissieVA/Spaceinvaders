//
// Created by Tijs Van Alphen on 23/03/2020.
//

#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include "../Sprite/Sprite.h"
#include "../Constants.h"


namespace SpaceInvaders::GameObjects
{
    class GameObject
    {
    public:
        GameObject(double xpos, double ypos, int width, int height);

        Sprite* getSprite() const;

        double getXpos() const;

        double getYpos() const;

        int getHeight() const;

        int getWidth() const;

        void setXpos(double xpos);

        void setYpos(double ypos);

        void setHeight(int height);

        void setWidth(int width);

        virtual void update(double timePast) = 0;

        virtual void move(double x_direction, double y_direction) ;

    protected:
        Sprite* sprite;
        double xPos = 0;
        double yPos = 0;
        int height = 0;
        int width = 0;

    };
}

#endif //GAME_GAMEOBJECT_H
