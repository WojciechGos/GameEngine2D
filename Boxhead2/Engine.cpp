#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>

#include "Engine.h"
#include "Control.h"
#include "Interface.h"
#include "Player.h"
#include "Enemy.h"
#include "Gameplay.h"

#include <iostream>


#define FPS 60.0


int SCREEN_POSITION_X = 30;
int SCREEN_POSITION_Y = 30;



#include "Engine.h"
/**
 * @brief Engine class responsible for managing the game engine.
 *
 * The Engine class is responsible for initializing and running the game engine.
 * It handles Allegro initialization, event processing, game loop, and various
 * game-related operations.
 */
Engine::Engine() {
	
}
/**
 * @brief Initialize the game engine.
 *
 * This function initializes Allegro and various Allegro addons required for the game.
 * It sets up timers, event queues, and the game display.
 */
void Engine::init() {

	/*
		INITIALIZATION AND INSTALATION
	*/
	al_init();
	//al_install_mouse();
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	
}
/**
 * @brief Run the game engine.
 *
 * This function sets up timers, event queues, and the game display. It then enters
 * the main game loop, handling events, updating the game state, and rendering.
 */
void Engine::run() {
	/*
		INITIALIZING VARIABLES
	*/
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_TIMER* enemy_timer = NULL;
	timer = al_create_timer(1. / (float)FPS);
	enemy_timer = al_create_timer(0.5);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_FONT* font = al_load_font("CONSOLA.ttf", 32, 0);
	ALLEGRO_DISPLAY* display = NULL;

	// Player create
	Player player(INITIAL_PLAYER_POSITION_X, INITIAL_PLAYER_POSITION_Y);

	Gameplay gameplay;
	int i = 0;

	/*
		SETTING WINDOWS PARAMETERS
	*/
	display = al_create_display(screenWidth, screenHeight);
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_window_position(display, SCREEN_POSITION_X, SCREEN_POSITION_Y);
	al_set_window_title(display, "Boxhead2");


	/*
		REGISTER EVENTS
	*/
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_timer_event_source(enemy_timer));
	al_start_timer(timer);
	al_start_timer(enemy_timer);


	/*
		 MAIN LOOP
	*/
	bool running = true;
	al_flip_display();
	ALLEGRO_EVENT event;

	//while (1) {

	//	Interface::menu();
	//	al_flip_display();

	//	ALLEGRO_EVENT ev;
	//	al_wait_for_event(event_queue, &ev);


	//	if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

	//		if (ev.mouse.x >= 600 && ev.mouse.x <= 1050
	//			&& ev.mouse.y >= 200 && ev.mouse.y <= 600) {
	//			break;
	//		}

	//	}

	//	if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
	//		break;
	//	}
	//}

	while (running) {
		
		al_wait_for_event(event_queue, &event);
		Interface::drawMap();
		player.drawLifeBar();


		/*
			EVENT HANDLERS
		*/
		handle_keyboard(&event, &player, &gameplay);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			running = false;
		}
		gameplay.run(&event, enemy_timer);
		/*
			DRAW
		*/

		for (auto& deadEnemy : gameplay.deadEnemies) {
			deadEnemy.render(&event);
		}

		for (auto& enemy : gameplay.enemies) {
			bool isInRange = enemy.updatePosition(&player.position);

			if (isInRange)
				if (player.giveDmg())
					running = false;

			enemy.render(&event);
		}

		player.render(&event);
		player.pointsCounter(font);
		al_flip_display();

	}

	while (1) {

		Interface::goodbye();
		al_flip_display();

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);



		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
	}
}


	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_font(font);
	al_destroy_event_queue(event_queue);
}



/**
 * @brief Handle keyboard input for player movement.
 *
 * This function is called in the game loop to handle keyboard input.
 * It updates the player's position based on the keys pressed.
 *
 * @param event The Allegro event containing keyboard input.
 * @param movement A pointer to the Movement object representing the player's position.
 */
void Engine::handle_keyboard(ALLEGRO_EVENT* event, Player* player, Gameplay* gameplay) {

	ALLEGRO_KEYBOARD_STATE keyState;
	if (event->type == ALLEGRO_EVENT_KEY_DOWN) {
		if (event->keyboard.keycode == ALLEGRO_KEY_SPACE) {
			player->shot(gameplay);
		}
	}

	if (event->type == ALLEGRO_EVENT_TIMER) {
		al_get_keyboard_state(&keyState);

		player->position.setActive(true);
		if (al_key_down(&keyState, ALLEGRO_KEY_D))
		{
			player->position.setDirection(RIGHT);
			if (!player->position.checkCollision()) {
				player->position.setX(player->position.getX() + MOVE);
			}
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_A))
		{
			player->position.setDirection(LEFT);
			if (!player->position.checkCollision()) {
				player->position.setX(player->position.getX() - MOVE);
			}
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_W))
		{
			player->position.setDirection(UP);
			if (!player->position.checkCollision()) {
				player->position.setY(player->position.getY() - MOVE);
			}
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_S))
		{
			player->position.setDirection(DOWN);
			if (!player->position.checkCollision()) {
				player->position.setY(player->position.getY() + MOVE);
			}
		}
		else
			player->position.setActive(false);
	}
}
/**
 * @brief Handle mouse input (not yet implemented).
 *
 * This function is a placeholder for handling mouse input, and it is currently empty.
 */
void Engine::handle_mouse() {



}


