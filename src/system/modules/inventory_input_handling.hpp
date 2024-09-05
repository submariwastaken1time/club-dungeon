void inv_input_to_action(std::string key, entt::registry &reg, entt::entity entity) {

  switch (key_bind_to_action[key]) {
    default: {
      reg.patch<actions>(entity,[&](auto &actions) {actions.actions = blank_inv_actions;});
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
