#ifndef INPUT_HANDLING_INCLUDES
#define INPUT_HANDLING_INCLUDES
#include <SDL.h>
#include <string>

#include "ECS_init.hpp"
#include "global_entity_values.hpp"
#include "game_actions.hpp"
#include "engine_tools/input_handling_data.hpp"
#endif

#ifndef INPUT_HANDLING
#define INPUT_HANDLING

void input_to_action(std::string key, entt::registry &reg, entt::entity entity) {
  // sets all actions to a blank action struct
  // all keys are then fed to an std::unordered_map, where it is converted to the actions in the
  // cases below, if the cases match, the function will patch the corresponding action to the action
  // struct, where it will be processed by the move function

  // additionally, the game renders with the coordinates (0,0) in the top left of the screen,
  // hence the negative y_move figure
  reg.patch<actions>(entity,[&](auto &actions) {actions.actions = blank_actions;});
  switch(key_bind_to_enum[key]) {
    default: {
      // this is meant to combat a quirk of c++ where the default block is ran first
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions = blank_actions;});
    } break;
    case UP_MOVE: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.y_move = -1;});
    } break;
    case DOWN_MOVE: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.y_move = 1;});
    } break;
    case RIGHT_MOVE: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.x_move = 1;});
    } break;
    case LEFT_MOVE: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.x_move = -1;});
    } break;
  }
}

#endif
