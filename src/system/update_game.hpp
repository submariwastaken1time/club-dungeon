#ifndef UPDATE_INCLUDES
#define UPDATE_INCLUDES

#include "../ECS_init.hpp"
#include "../global_entity_values.hpp"
#include "../game_actions.hpp"
#include "modules/input_handling.hpp"
#include "modules/move_or_bump.hpp"
#include "modules/attack.hpp"
#include "modules/kill.hpp"
#include "../states.hpp"
#endif

#ifndef UPDATE_GAME
#define UPDATE_GAME
// update the game

void update_game(entt::registry &reg) {
  if (G_state == ingame) {
  auto view_moves = reg.view<actions>();
  auto player_view = reg.view<player_marker>();
  auto name_view = reg.view<name>();

  for (auto entity : view_moves) {
    move_or_bump(entity, reg);
  }
  for (auto entity : name_view) {
    kill(reg,entity);
  }
}
}
// prompt the player for inputs

void prompt_player(entt::registry &reg, std::string key) {

  auto view_player = reg.view<player_marker>();

  for (auto player : view_player) {
    input_to_action(key, reg, player);
  }
}
#endif
