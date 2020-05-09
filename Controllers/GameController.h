//
// Created by Tijs Van Alphen on 23/03/2020.
//

#ifndef GAME_GAMECONTROLLER_H
#define GAME_GAMECONTROLLER_H

#include "../Window/Window.h"
#include "../Factories/AFactory.h"
#include "../Events/EventManager.h"
#include "../GameObject/Bullet.h"
#include "../GameObject/Health.h"

namespace SpaceInvaders::Controllers
{
    class GameController
    {
    public:
        GameController();

        ~GameController();


        static GameController &getInstance()
        {
            static GameController instance;
            return instance;
        }

        GameController(GameController const &) = delete;

        void operator=(GameController) = delete;

        void setWindow(SpaceInvaders::Window::Window* setWindow)
        { fWindow = setWindow; }

        SpaceInvaders::Window::Window* getWindow()
        { return fWindow; }

        Factories::AFactory* getFactory() const;

        void setFactory(Factories::AFactory* factory);

        Events::EventManager* getEventmanager();



    private:
        SpaceInvaders::Window::Window* fWindow;
        Factories::AFactory* factory;
        Events::EventManager* eventManager;


    };
}

#endif //GAME_GAMECONTROLLER_H
