#ifndef Engine_h
#define Engine_h

#include <allegro5/allegro.h>
#include "Control.h"
#include "Player.h"
#include "Gameplay.h"

#define screenWidth 1800
#define screenHeight 900

#define MOVE 5

class Engine {
public:
    Engine();

    void init();
    void run();

private:


    void handle_keyboard(ALLEGRO_EVENT* event, Player* player, Gameplay *gameplay);

    void handle_mouse();

};

#endif