#ifndef MOVE_INCLUDES
#define MOVE_INCLUDES

#include <iostream>

#include "ECS_init.hpp"
#include "global_entity_values.hpp"

#endif

#ifndef MOVE
#define MOVE

// moves the entity

void move(entt::entity entity, entt::registry &reg)  {
  // getting the action components
  auto x_movement = reg.get<actions>(entity).actions.x_move;
  auto y_movement = reg.get<actions>(entity).actions.y_move;
  // calculating the new position of the entity
  auto new_x = reg.get<pos>(entity).pos_x + x_movement;
  auto new_y = reg.get<pos>(entity).pos_y + y_movement;
  // patching the new position to the entity
  reg.patch<pos>(entity, [&](auto &pos) {pos.pos_x = new_x;});
  reg.patch<pos>(entity, [&](auto &pos) {pos.pos_y = new_y;});

}

#endif
