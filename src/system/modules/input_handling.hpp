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
  reg.patch<actions>(entity,[&](auto &actions) {actions.actions = blank_actions;});
  switch(key_bind_to_enum[key]) {
    default: {
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
