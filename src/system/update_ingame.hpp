#ifndef UPDATE_INCLUDES
#define UPDATE_INCLUDES

#include "../ECS_init.hpp"
#include "../global_entity_values.hpp"
#include "../game_actions.hpp"
#include "modules/ingame_input_handling.hpp"
#include "modules/move_or_bump.hpp"
#include "modules/attack.hpp"
#include "modules/kill.hpp"
#include "../states.hpp"
#include "update_inventory.hpp"
#endif

#ifndef UPDATE_GAME
#define UPDATE_GAME
// update the game

void update_ingame(entt::registry &reg) {
  auto view_moves = reg.view<actions>();
  auto player_view = reg.view<player_marker>();
  auto monster_view = reg.view<name,hp>();

  for (auto entity : view_moves) {
    move_or_bump(entity, reg);
  }
  for (auto entity : monster_view) {
    kill(reg,entity);
  }
  for (auto entity : player_view) {
    switch_to_inventory(reg,entity);
  }
}
// prompt the player for inputs

void prompt_player_ingame(entt::registry &reg, std::string key) {

  auto view_player = reg.view<player_marker>();

  for (auto player : view_player) {
    ingame_input_to_action(key, reg, player);
  }
}
#endif
