cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})
set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Game main.cpp Factories/AFactory.cpp Factories/AFactory.h Game.cpp Game.h Window/Window.cpp Window/Window.h SDL/Window/SDLWindow.cpp SDL/Window/SDLWindow.h SDL/Factories/SDLFactory.cpp SDL/Factories/SDLFactory.h Events/EventManager.cpp Events/EventManager.h Events/EventObserver.cpp Events/EventObserver.h GameObject/GameObject.cpp GameObject/GameObject.h Sprite/Sprite.cpp Sprite/Sprite.h SDL/Sprite/SDLSprite.cpp SDL/Sprite/SDLSprite.h Controllers/GameController.cpp Controllers/GameController.h GameObject/Player.cpp GameObject/Player.h GameObject/Enemy.cpp GameObject/Enemy.h Constants.h Controllers/EnemyController.cpp Controllers/EnemyController.h GameObject/Bullet.cpp GameObject/Bullet.h Controllers/BulletController.cpp Controllers/BulletController.h GameObject/Health.cpp GameObject/Health.h Controllers/MiscController.cpp Controllers/MiscController.h GameObject/BonusShip.cpp GameObject/BonusShip.h Text/Text.cpp Text/Text.h SDL/Text/SDLText.cpp SDL/Text/SDLText.h)
target_link_libraries(Game ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)