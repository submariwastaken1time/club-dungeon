// temp function to test combat
#ifndef T_SET_ORC_POS_INCLUDES
#define T_SET_ORC_POS_INCLUDES
#include "../../ECS_init.hpp"
#include "../../system/modules/set_pos.hpp"
#endif

#ifndef T_SET_ORC_POS
#define T_SET_ORC_POS
void T_set_orc_pos(entt::registry &reg) {

auto orc_view = reg.view<name>();
for (entt::entity entity : orc_view) {
  if (reg.get<name>(entity).name == "Orc") {
  entt::entity orc = entity;
  set_pos(orc, reg, 5 , 5);
  }
}
}
#endif
