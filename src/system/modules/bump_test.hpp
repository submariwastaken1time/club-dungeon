#ifndef BUMP_TEST_INCLUDE
#define BUMP_TEST_INCLUDE

#include <stdlib.h>
#include <iostream>
#include "../../ECS_init.hpp"

#endif

#ifndef BUMP_TEST
#define BUMP_TEST

bool bump_test(entt::entity entity, entt::registry &reg, int x_dir_to_test, int y_dir_to_test) {
  if (x_dir_to_test != 0 || y_dir_to_test != 0) {
    auto entity_pos = reg.get<pos>(entity);

    auto pos_view = reg.view<pos>();
    entt::entity *ent_t_check;

    for (entt::entity entity_to_check : pos_view) {
      auto entity_to_check_pos = reg.get<pos>(entity_to_check);
      if (entity_to_check_pos.pos_x == entity_pos.pos_x + x_dir_to_test) {
        if (entity_to_check_pos.pos_y == entity_pos.pos_y + y_dir_to_test) {

          reg.patch<bumped_into>(entity, [&](auto &b_into){b_into.bumped_ent = entity_to_check;});

          #ifdef debug_mode
          if (reg.get<bumped_into>(entity).bumped_ent != entt::null){
              std::cout << "Sucessful bump test" << std::endl;
          }
          #endif

          ent_t_check = &entity_to_check;
        }
      }

      ent_t_check = &entity_to_check;
    }
    auto bumped_entity = reg.get<bumped_into>(entity).bumped_ent;
    auto no_coll_entity = reg.get<collision_tag>(*ent_t_check).coll;
    if (bumped_entity == entt::null || !no_coll_entity) {
      return false;
    } else {
      return true;
    }
  } else {
    #ifdef debug_mode
    std::cout << "no bumps" << std::endl;
    #endif
    return false;
  }
}
#endif
