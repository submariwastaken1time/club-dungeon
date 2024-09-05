#ifndef UPDATE_INVENTORY_INCLUDES
#define UPDATE_INVENTORY_INCLUDES
#include <iterator>

#include "../ECS_init.hpp"
#include "../engine_tools/inventory_tools.hpp"
#include "modules/use.hpp"
#include "../global_entity_values.hpp"
#include "../states.hpp"
#include "../engine_tools/state_manager.hpp"

#endif

#ifndef UPDATE_INVENTORY
#define UPDATE_INVENTORY
void update_inventory(entt::registry &reg) {
  auto view_player = reg.view<player_marker>();
  for (entt::entity entity : view_player) {
  auto view_inventory = reg.view<in_inventory>();
  auto act = reg.get<actions>(entity).actions;
    reg.patch<actions>(entity, [&](auto &actns) {actns.actions.i_highlight_item =
    act.i_highlight_item + act.i_y_move;});
    if (act.i_select) {
      use(reg,entity,*std::ranges::next(view_inventory.begin(),act.i_highlight_item));
    }
    if (act.i_quit) {
      set_ingame();
    }
  }
}
#endif
