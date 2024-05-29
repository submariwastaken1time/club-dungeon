#ifndef GLOBAL_ENTITY_VALUES
#define GLOBAL_ENTITY_VALUES

// all of the components that entities can have in the game

struct name {std::string name;};
struct pos {int pos_x; int pos_y;};
struct icon {char icon;};
struct fg {int fg_r; int fg_g; int fg_b;};
struct hp {int hp;};
struct atk {int atk;};
struct xp {int xp; int level;};
struct AI {int AI;};

#endif
