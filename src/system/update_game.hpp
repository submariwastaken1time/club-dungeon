#ifndef UPDATE_INCLUDES
#define UPDATE_INCLUDES

#include "../ECS_init.hpp"
#include "../global_entity_values.hpp"
#include "../game_actions.hpp"
#include "modules/input_handling.hpp"
#include "modules/move.hpp"
#include "modules/attack.hpp"

#endif

#ifndef UPDATE_GAME
#define UPDATE_GAME
// update only the movement

void update_game(entt::registry &reg) { auto view_moves = reg.view<actions>();
auto player_view = reg.view<player_marker>();
auto orc_view = reg.view<name>();
for (auto entity : view_moves) {
    move(entity, reg);
  for (auto player : player_view) {
    attack(player, reg, player);
    }
  }
}

// prompt the player for inputs

void prompt_player(entt::registry &reg, std::string key) { auto view_player = reg.view<player_marker>();
  for (auto player : view_player) {
    input_to_action(key, reg, player);
  }
}
#endif
