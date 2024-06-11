#ifndef INPUT_HANDLING_INCLUDES
#define INPUT_HANDLING_INCLUDES
#include <SDL.h>
#include <string>

#include "game_actions.hpp"
#include "input_handling_data.hpp"
#endif

void key_to_action(std::string key) {
  game_actions = blank_actions;
  switch(key_bind_to_enum[key]) {
    default: {
      game_actions = blank_actions;
    } break;
    case UP_MOVE: {
      game_actions.y_move = 1;
    } break;
    case DOWN_MOVE: {
      game_actions.y_move = -1;
    } break;
    case RIGHT_MOVE: {
      game_actions.x_move = 1;
    } break;
    case LEFT_MOVE: {
      game_actions.x_move = -1;
    } break;
  }
}
