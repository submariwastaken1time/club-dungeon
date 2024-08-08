#ifndef GLOBAL_ENTITY_VALUES_INCLUDES
#define GLOBAL_ENTITY_VALUES_INCLUDES
#include <string>

#include "game_actions.hpp"
#endif

#ifndef GLOBAL_ENTITY_VALUES // these are preprocessor directives to prevent conflicts with
#define GLOBAL_ENTITY_VALUES // other files in compilation. this will prevent the compiler
                                      // header file twice from including a library or header
// all of the components that entities can have in the game
// can also be used as flags for the system to operate on only certain entities
struct player_marker{}; // marker for the player
struct name {std::string name;};
struct pos {int pos_x; int pos_y; int pos_level;};
struct icon {char icon;};
struct fg {uint8_t fg_r; uint8_t fg_g; uint8_t fg_b;};
struct hp {int hp;};
struct atk {int atk;};
struct xp {int xp; int level;};
struct AI {uint8_t AI;};
struct actions {struct game_actions actions;};
struct bumped_tag {bool bumped_tag;};
#endif
