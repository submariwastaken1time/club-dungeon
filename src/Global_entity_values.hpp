#ifndef GLOBAL_ENTITY_VALUES_INCLUDES // these are preprocessor directives to prevent conflicts with
#define GLOBAL_ENTITY_VALUES_INCLUDES // other files in compilation. this will prevent the compiler
                                      // header file twice from including a library or header
// all of the components that entities can have in the game
// can also be used as flags for the system to operate on only certain entities

struct name {std::string name;};
struct pos {int pos_x; int pos_y;};
struct icon {char icon;};
struct fg {int fg_r; int fg_g; int fg_b;};
struct hp {int hp;};
struct atk {int atk;};
struct xp {int xp; int level;};
struct AI {int AI;};

#endif
