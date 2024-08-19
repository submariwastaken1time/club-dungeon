#ifndef PLAYER_INCLUDES
#define PLAYER_INCLUDES

#include "../ECS_init.hpp"
#include "../global_entity_values.hpp"
#include "../game_actions.hpp"
#include "../engine_tools/set_nearby_tools.hpp"
#endif

entt::entity create_player(entt::registry &registry) {
  auto player = registry.create();
  registry.emplace<player_marker>(player);
  registry.emplace<name>(player,"You");
  registry.emplace<pos>(player, 0 , 0 , 0);
  registry.emplace<icon>(player, '@');
  registry.emplace<fg>(player, fg{255u , 255u , 255u} );
  registry.emplace<hp>(player, 0 );
  registry.emplace<atk>(player, 0 );
  registry.emplace<xp>(player, 0, 0 );
  registry.emplace<AI>(player, AI{0u} );
  registry.emplace<actions>(player, blank_actions);
  registry.emplace<bumped_tag>(player, false);
  registry.emplace<nearby_cont>(player, nearby_keys);
  return player;
}
