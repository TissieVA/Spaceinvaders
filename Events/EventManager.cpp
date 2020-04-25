//
// Created by Tijs Van Alphen on 4/03/2020.
//

#include "EventManager.h"

Events::EventManager::~EventManager() {
    this->observers.clear();
}

void Events::EventManager::addObserver(Events::EventObserver *observer) {
    this->observers.push_back(observer); //put at the end of vector
}

void Events::EventManager::KeyDown(Events::Key press) {

    for (auto observer : observers)
        observer->KeyDown(press);
}

void Events::EventManager::KeyUp(Events::Key press) {
    for (auto observer : observers)
        observer->KeyUp(press);
}





