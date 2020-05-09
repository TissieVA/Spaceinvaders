//
// Created by Tijs Van Alphen on 4/03/2020.
//

#ifndef GAME_EVENTOBSERVER_H
#define GAME_EVENTOBSERVER_H

namespace SpaceInvaders::Events {

    enum Key{NOTHING, LEFT, RIGHT, SPACE};

    class EventObserver{
    public:
        virtual void KeyDown(Key press) {};

        virtual void KeyUp(Key press) {};
    };
}

#endif //GAME_EVENTOBSERVER_H
