#ifndef Player_h
#define Player_h

#include "Control.h"
#include "Gameplay.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define INITIAL_PLAYER_POSITION_X 100
#define INITIAL_PLAYER_POSITION_Y 100
/**
 * @brief Player class represents the player character in the game.
 *
 * @The Player class manages the player's position, movement, health, points, and rendering on the screen.
 * It includes functions for rendering the player, rendering shots, handling collisions, drawing a life bar,
 * and updating points. Additionally, the constructor initializes the player object with a specified position.
 */

class Player {
private:
    int lifePoints = 6;
    void renderShot();
    ALLEGRO_BITMAP* player;


public:
    Movement position;
    Player(int x, int y);
    int points = 0;
    void render(ALLEGRO_EVENT *event);
    void shot(Gameplay* gameplay);
    void drawLifeBar();
    void pointsCounter(ALLEGRO_FONT* font);
    bool giveDmg();
};


#endif
