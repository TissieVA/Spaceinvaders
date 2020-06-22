//
// Created by Tijs Van Alphen on 20/06/2020.
//

#ifndef GAME_ICON_H
#define GAME_ICON_H

#include <string>

namespace SpaceInvaders
{
    class Icon
    {
    public:
        Icon(std::string path);

        virtual void loadIcon() =0; //will be used on SDL side
        virtual void* dispIcon()=0;

    protected:
        std::string path;
    };
}

#endif //GAME_ICON_H
