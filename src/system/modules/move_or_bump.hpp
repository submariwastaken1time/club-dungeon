#ifndef MOVE_INCLUDES
#define MOVE_INCLUDES

#include <iostream>

#include "reset_bumped_entity.hpp"
#include "../../ECS_init.hpp"
#include "../../global_entity_values.hpp"
#include "bump_test.hpp"
#include "attack.hpp"
#include "../../states.hpp"
#include "pickup.hpp"
#endif

#ifndef MOVE
#define MOVE

void move_or_bump(entt::entity entity, entt::registry &reg)  {
  if (G_state == ingame) {
  auto x_movement = reg.get<actions>(entity).actions.x_move;
  auto y_movement = reg.get<actions>(entity).actions.y_move;

  auto new_x = reg.get<pos>(entity).pos_x + x_movement;
  auto new_y = reg.get<pos>(entity).pos_y + y_movement;

  if (bump_test(entity, reg, x_movement, y_movement) == true) {
    auto b_ent = reg.get<bumped_into>(entity).bumped_ent;
    if (reg.all_of<enemy>(b_ent)) {
      attack(entity, reg, b_ent);
    } else if (reg.all_of<item>(b_ent)) {
      pickup(reg, b_ent);
    }
    reset_bumped_component(reg, entity);
  } else {
    reg.patch<pos>(entity, [&](auto &pos) {pos.pos_x = new_x;});
    reg.patch<pos>(entity, [&](auto &pos) {pos.pos_y = new_y;});

    #ifdef debug_mode
    std::cout << "y: ";
    std::cout << reg.get<pos>(entity).pos_y << std::endl;
    std::cout << "x: ";
    std::cout << reg.get<pos>(entity).pos_x << std::endl;
    #endif
  }
  }
}

#endif
