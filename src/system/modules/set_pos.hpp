#ifndef SET_POS_INCLUDES
#define SET_POS_INCLUDES

#include "../../ECS_init.hpp"
#include "../../states.hpp"
#endif

#ifndef SET_POS
#define SET_POS
void set_pos(entt::entity entity, entt::registry &reg, int x , int y) {
  if (G_state == ingame) {
  reg.patch<pos>(entity, [&](auto &pos) {pos.pos_x = x;});
  reg.patch<pos>(entity, [&](auto &pos) {pos.pos_y = y;});
  }
}
#endif
