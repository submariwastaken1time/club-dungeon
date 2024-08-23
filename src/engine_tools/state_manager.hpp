#ifndef STATE_MANAGER_INCLUDES
#define STATE_MANAGER_INCLUDES
#include <iostream>
#include "../states.hpp"
#endif

#ifndef STATE_MANAGER
#define STATE_MANAGER
void quit_game() {G_state = quit;}
void pause_game() {G_state = pause_menu; }
void set_ingame() {G_state = ingame;}
void set_menu1() {G_state = menu_1;}
void set_inventory_screen() {G_state = inventory_screen;}
#endif
