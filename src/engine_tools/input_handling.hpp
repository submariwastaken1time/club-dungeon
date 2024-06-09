#ifndef INPUT_HANDLING_INCLUDES
#define INPUT_HANDLING_INCLUDES
#include <SDL.h>
#include <string>

#include "game_actions.hpp"
#endif

struct key_bind_name {
  std::string up_key = "Up";
} key_bind_name;

void reset_inputs() {
  game_actions.x_move = NULL;
  game_actions.y_move = NULL;
}

void key_to_action(std::string key) {

  if(key == key_bind_name.up_key) {
    game_actions.y_move = 1;
  }
  else {
    reset_inputs();
  }

}
