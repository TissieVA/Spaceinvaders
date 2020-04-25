//
// Created by Tijs Van Alphen on 4/03/2020.
//

#ifndef GAME_EVENTMANAGER_H
#define GAME_EVENTMANAGER_H

#include <vector>
#include "EventObserver.h"

using namespace std;

namespace Events {
    class EventManager {
    public:
        ~EventManager();

        void addObserver(EventObserver *observer);

        void KeyDown(Key press);

        void KeyUp(Key press);

    private:
        vector<EventObserver *> observers; // vector because we won't know yet how many observers there will be


    };
}


#endif //GAME_EVENTMANAGER_H
