#ifndef INPUT_HANDLING_INCLUDES
#define INPUT_HANDLING_INCLUDES
#include <SDL.h>
#include <string>

#include "game_actions.hpp"
#include "input_handling_data.hpp"
#endif

void key_to_action(std::string key, entt::registry &reg) {
  game_actions = blank_actions;
  auto player = reg.view<player_marker>();
  switch(key_bind_to_enum[key]) {
    default: {
      reg.get<actions>(player).game_actions = blank_actions;
    } break;
    case UP_MOVE: {
      reg.get<actions>(player).game_actions.y_move = 1;
    } break;
    case DOWN_MOVE: {
      reg.get<actions>(player).game_actions.y_move = -1;
    } break;
    case RIGHT_MOVE: {
      reg.get<actions>(player).game_actions.x_move = 1;
    } break;
    case LEFT_MOVE: {
      reg.get<actions>(player).game_actions.x_move = -1;
    } break;
  }
}
