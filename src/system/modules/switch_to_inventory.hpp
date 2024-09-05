#ifndef SWITCH_TO_INVENTORY_INCLUDES
#define SWITCH_TO_INVENTORY_INCLUDES
#include "../ECS_init.hpp"
#include "../global_entity_values.hpp"
#include "../engine_tools/state_manager.hpp"
#endif

#ifndef SWITCH_TO_INVENTORY
#define SWITCH_TO_INVENTORY
void switch_to_inventory(entt::registry &reg, entt::entity player) {
  auto i_open = reg.get<actions>(player).actions.open_inventory;
    if (i_open) {
    set_inventory_screen();
  }
}
#endif
