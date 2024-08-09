#ifndef BUMP_TEST_INCLUDE
#define BUMP_TEST_INCLUDE

#include <stdlib.h>
#include "ECS_init.hpp"
#endif

#ifndef BUMP_TEST
#define BUMP_TEST

// the function used to determine whether to bump/attack/interact into/with things or not

entt::entity bump_test(entt::entity entity, entt::registry &reg, int x_dir_to_test, int y_dir_to_test) {
  auto entity_pos_struct = reg.get<pos>(entity);
  auto view_pos_new = reg.view<pos>();
  auto is_player = reg.all_of<player_marker>();
  for (entt::entity ent_nearby : view_pos_new) {
    auto test_pos_struct = reg.get<pos>(ent_nearby);
    if (entity_pos_struct.pos_x = test_pos_struct_x && entity_pos_struct.pos_y = test_pos_struct_y &&
    !is_player) {
      reg.patch<entity>([&](auto &bumped) {bumped.bumped_tag = true;});
      return ent;
    } else {
      #ifdef debug_mode
      std::cout << "there's nothing there" << std:endl;
      #endif
    }
  }
}
#endif
