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

namespace Controllers
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

        void setWindow(Window* setWindow)
        { fWindow = setWindow; }

        Window* getWindow()
        { return fWindow; }

        Factories::AFactory* getFactory() const;

        void setFactory(Factories::AFactory* factory);

        Events::EventManager* getEventmanager();



    private:
        Window* fWindow;
        Factories::AFactory* factory;
        Events::EventManager* eventManager;


    };
}

#endif //GAME_GAMECONTROLLER_H
