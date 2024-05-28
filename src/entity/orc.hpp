#ifndef ORC
#define ORC

#include "ECS_init.hpp"
#include "Global_entity_values.hpp"
/*
(*) monster/entity table:
ID | name | position | character | foreground color | hp | atk | xp | AI
*/

inline void create_orc(entt::registry registry) {
  auto orc = registry.create();
  registry.emplace<struct name>(orc,"Orc");
  registry.emplace<struct pos>(orc, 0. , 0);
  registry.emplace<struct icon>(orc, "O");
  registry.emplace<struct fg>(orc, 0.,0.,0);
  registry.emplace<struct hp>(orc, 0);
  registry.emplace<struct atk>(orc, 0);
  registry.emplace<struct xp>(orc, 0);
  registry.emplace<struct AI>(orc, 0);
}

#endif
