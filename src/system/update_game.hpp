#ifndef UPDATE_INCLUDES
#define UPDATE_INCLUDES

#include "ECS_init.hpp"
#include "global_entity_values.hpp"
#include "game_actions.hpp"
#include "system/modules/input_handling.hpp"
#include "system/modules/move.hpp"

#endif

#ifndef UPDATE_GAME
#define UPDATE_GAME
// update only the movement

void update_monsters(entt::registry &reg) { auto view_moves = reg.view<actions>();
for (auto entity : view_moves) {
    move(entity, reg);
  }
}
// update only the player based on inputs

void update_player(entt::registry &reg, std::string key) { auto view_player = reg.view<player_marker>();
  for (auto player : view_player) {
    input_to_action(key, reg, player); // feeds the necessary parameters to the function. cuts down on
    // lines of code
  }
}
#endif
