//
// Created by Tijs Van Alphen on 23/03/2020.
//

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include <string>

class Sprite {
public:
    Sprite(std::string path);
    virtual void loadSprite()=0;
    virtual void* dispSprite()=0;

protected:
    std::string path;
};


#endif //GAME_SPRITE_H
