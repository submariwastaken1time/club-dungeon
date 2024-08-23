#ifndef GAME_ACTIONS
#define GAME_ACTIONS
struct game_actions {
  int x_move = 0;
  int y_move = 0;
  bool open_inventory = false;
  int i_y_move = 0;
  bool i_select = false;
  bool i_quit = false;
};

struct game_actions blank_actions;

enum action_dictionary {
  NONE,
  UP_MOVE,
  DOWN_MOVE,
  LEFT_MOVE,
  RIGHT_MOVE,
  UP_L_MOVE,
  DOWN_L_MOVE,
  UP_R_MOVE,
  DOWN_R_MOVE,

  OPEN_INVENTORY,
  QUIT_INVENTORY,
  SELECT_ITEM,
};
#endif
