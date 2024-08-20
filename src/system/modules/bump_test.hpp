#ifndef BUMP_TEST_INCLUDE
#define BUMP_TEST_INCLUDE

#include <stdlib.h>
#include <iostream>
#include "../../ECS_init.hpp"

#endif

#ifndef BUMP_TEST
#define BUMP_TEST

bool bump_test(entt::entity entity, entt::registry &reg, int x_dir_to_test, int y_dir_to_test) {
  auto entity_pos = reg.get<pos>(entity);

  auto pos_view = reg.view<pos>();
  for (entt::entity entity_to_check : pos_view) {

    auto entity_to_check_pos = reg.get<pos>(entity_to_check);
    if (entity_pos.pos_x + x_dir_to_test == entity_to_check_pos.pos_x) {
      if (entity_pos.pos_y + y_dir_to_test == entity_to_check_pos.pos_y) {
        reg.patch<bumped_into>(entity, [&](auto bumped_into){bumped_into.bumped_ent = entity_to_check;});
        #ifdef debug_mode
        std::cout << "Sucessful bump test";
        #endif
        return true;
      }
      return false;
    }
    return false;
  }
  return false;
}
#endif
