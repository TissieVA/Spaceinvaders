//
// Created by tijsv on 20/06/2020.
//

#ifndef GAME_ICON_H
#define GAME_ICON_H

#include <string>

namespace SpaceInvaders::Icon
{
    class Icon
    {
    public:
        Icon(std::string path);

        virtual void loadIcon() =0;
        virtual void* dispIcon()=0;

    protected:
        std::string path;
    };
}

#endif //GAME_ICON_H
