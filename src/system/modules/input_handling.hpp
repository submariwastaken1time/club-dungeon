#ifndef INPUT_HANDLING_INCLUDES
#define INPUT_HANDLING_INCLUDES
#include <SDL.h>
#include <string>

#include "../../states.hpp"
#include "../../ECS_init.hpp"
#include "../../global_entity_values.hpp"
#include "../../game_actions.hpp"
#include "../../engine_tools/input_handling_data.hpp"
#endif

#ifndef INPUT_HANDLING
#define INPUT_HANDLING

void input_to_action(std::string key, entt::registry &reg, entt::entity entity) {
  // auto patch_actions = reg.patch<actions>;
  if (G_state == ingame) {
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
  } else if (G_state == inventory_screen) {
    switch (key_bind_to_action[key]) {
      default: {
        reg.patch<actions>(entity,[&](auto &actions) {actions.actions = blank_actions;});
      } break;
      case UP_MOVE: {
        reg.patch<actions>(entity,[&](auto &actions) {actions.actions.i_y_move = -1;});
      } break;
      case DOWN_MOVE: {
        reg.patch<actions>(entity,[&](auto &actions) {actions.actions.i_y_move = 1;});
      } break;
      case LEFT_MOVE: {
        // show tooltips/info
      } break;
      case SELECT_ITEM: {
        reg.patch<actions>(entity,[&](auto &actions) {actions.actions.i_select = true;});
      } break;
      case QUIT_INVENTORY: {
        reg.patch<actions>(entity,[&](auto &actions) {actions.actions.i_quit = true;});
      } break;
    }
  }
}

#endif
