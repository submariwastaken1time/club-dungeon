#ifndef UPDATE_INVENTORY_INCLUDES
#define UPDATE_INVENTORY_INCLUDES

#include "ECS_init.hpp"
#include "global_entity_values.hpp"

#endif

#ifndef UPDATE_INVENTORY
#define UPDATE_INVENTORY
void update_inventory(entt::registry &reg, entt::entity entity) {
  auto actions = reg.get<actions>.actions;

  reg.patch<actions>(entity, [&](auto &actns){actns.actions.i_highlight_char =
  actions.i_highlight_char + i_y_move});
}
#endif
