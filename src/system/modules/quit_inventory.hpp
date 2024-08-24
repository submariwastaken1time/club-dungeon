#ifndef QUIT_INVENTORY_INCLUDES
#define QUIT_INVENTORY_INCLUDES

#include "../../ECS_init.hpp"
#include "../../states.hpp"
#include "../../engine_tools/state_manager"

#endif

#ifndef QUIT_INVENTORY
#define QUIT_INVENTORY
void quit_inventory(entt::registry &reg, entt::entity entity) {
  if (G_state == inventory_screen) {
    if (reg.get<actions>.actions.i_quit) {
      set_ingame();
    }
  }
}
#endif
