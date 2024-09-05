#ifndef INGAME_INPUT_HANDLING_INCLUDES
#define INGAME_INPUT_HANDLING_INCLUDES
#include <SDL.h>
#include <string>

#include "../../states.hpp"
#include "../../ECS_init.hpp"
#include "../../global_entity_values.hpp"
#include "../../game_actions.hpp"
#include "../../engine_tools/input_handling_data.hpp"
#endif

#ifndef INGAME_INPUT_HANDLING
#define INGAME_INPUT_HANDLING

void ingame_input_to_action(std::string key, entt::registry &reg, entt::entity entity) {

  reg.patch<actions>(entity,[&](auto &actions) {actions.actions = blank_actions;});
  switch(key_bind_to_action[key]) {
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
    case UP_L_MOVE: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.x_move = -1;});
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.y_move = -1;});
    } break;
    case UP_R_MOVE: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.x_move = 1;});
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.y_move = -1;});
    } break;
    case DOWN_L_MOVE: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.x_move = -1;});
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.y_move = 1;});
    } break;
    case DOWN_R_MOVE: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.x_move = 1;});
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.y_move = 1;});
    } break;
    case OPEN_INVENTORY: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions.open_inventory = true;});
    } break;
  }
}

#endif
