#ifndef MOVE_INCLUDES
#define MOVE_INCLUDES

#include <iostream>

#include "ECS_init.hpp"
#include "global_entity_values.hpp"

#endif

#ifndef MOVE
#define MOVE

void move(entt::entity entity, entt::registry &reg)  {
  auto x_movement = reg.get<actions>(entity).actions.x_move;
  auto y_movement = reg.get<actions>(entity).actions.y_move;

  auto new_x = reg.get<pos>(entity).pos_x + x_movement;
  auto new_y = reg.get<pos>(entity).pos_y + y_movement;

  reg.patch<pos>(entity, [&](auto &pos) {pos.pos_x = new_x;});
  reg.patch<pos>(entity, [&](auto &pos) {pos.pos_y = new_y;});

  #ifdef debug_mode
  std::cout << "y: ";
  std::cout << reg.get<pos>(entity).pos_y << std::endl;
  std::cout << "x: ";
  std::cout << reg.get<pos>(entity).pos_x << std::endl;
  #endif
}

#endif
