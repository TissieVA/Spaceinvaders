//
// Created by Tijs Van Alphen on 4/03/2020.
//

#include "EventManager.h"
using namespace SpaceInvaders::Events;

EventManager::~EventManager() {
    this->observers.clear();
}

void EventManager::addObserver(Events::EventObserver *observer) {
    this->observers.push_back(observer);
}

void EventManager::KeyDown(Events::Key press) {

    for (auto observer : observers)
        observer->KeyPressedDown(press);  //method of oberver, in our case player who is an eventobserver
}

void EventManager::KeyUp(Events::Key press) {
    for (auto observer : observers)
        observer->KeyPressedUp(press);
}





