#ifndef SET_NEARBY_TOOLS_INCLUDES
#define SET_NEARBY_TOOLS_INCLUDES

#include "ECS_init.hpp"

#endif

#ifndef SET_NEARBY_TOOLS
#define SET_NEARBY_TOOLS
enum nearby_directions {
  UP,
  DOWN,
  LEFT,
  RIGHT,
  UP_L,
  DOWN_L,
  UP_R,
  DOWN_R
};

auto player_view = reg.view<player_marker>()
for (entt::entity : player_view) {
  auto player_pos = reg.get<pos>(entity);
}

std::unordered_map< int, int, nearby_directions> nearby_map = {
  {player_pos.pos_x, player_pos.pos_y + 1, true},
  {player_pos.pos_x, player_pos.pos_y - 1, true},
  {player_pos.pos_x + 1, player_pos.pos_y, true},
  {player_pos.pos_x - 1, player_pos.pos_y, true},
  {player_pos.pos_x - 1, player_pos.pos_y + 1, true},
  {player_pos.pos_x + 1, player_pos.pos_y + 1, true},
  {player_pos.pos_x - 1, player_pos.pos_y - 1, true},
  {player_pos.pos_x + 1, player_pos.pos_y - 1, true}
}
#endif
