#include "../states.hpp"

void quit_game() { G_state = quit;}
void pause_game() { G_state = pause_menu; }
void set_ingame() {G_state = ingame;}
void set_menu1() {G_state = menu_1;}
void set_inventory_screen() {G_state = inventory_screen;}
