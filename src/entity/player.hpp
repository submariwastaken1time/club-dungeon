#ifndef PLAYER_INCLUDES
#define PLAYER_INCLUDES

#include "ECS_init.hpp"
#include "Global_entity_values.hpp"
#include "game_actions.hpp"

#endif

entt::entity create_player(entt::registry &registry) {
  auto player = registry.create();
  registry.emplace<player_marker>(player);
  registry.emplace<name>(player,"You");
  registry.emplace<pos>(player, 0 , 0 , 0);
  registry.emplace<icon>(player, '@');
  registry.emplace<fg>(player, 255 , 255 , 255 );
  registry.emplace<hp>(player, 0 );
  registry.emplace<atk>(player, 0 );
  registry.emplace<xp>(player, 0 );
  registry.emplace<AI>(player, 0 );
  registry.emplace<actions>(player, blank_actions);
  return player;
}
