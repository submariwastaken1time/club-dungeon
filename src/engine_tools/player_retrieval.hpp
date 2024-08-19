#ifndef PLAYER_RETRIEVAL_INCLUDES
#define PLAYER_RETRIEVAL_INCLUDES

#include "../ECS_init.hpp"

#endif

#ifndef PLAYER_RETRIEVAL
#define PLAYER_RETRIEVAL

auto player_view = reg.view<player_marker>()
for (entt::entity entity : player_view) {
  entt::entity player = entity;
}

#endif
