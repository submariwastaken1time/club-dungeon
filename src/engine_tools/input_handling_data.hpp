#ifndef INPUT_HANDLING_DATA
#define INPUT_HANDLING_DATA

#include <unordered_map>

std::unordered_map<std::string, action_dictionary> key_bind_to_action = {
  {"", NONE},
  {"Up", UP_MOVE},
  {"Down", DOWN_MOVE},
  {"Left", LEFT_MOVE},
  {"Right", RIGHT_MOVE},
  {"Y", UP_L_MOVE},
  {"U", UP_R_MOVE},
  {"B", DOWN_L_MOVE},
  {"N", DOWN_R_MOVE},

  {"I", OPEN_INVENTORY},
  {"Return", SELECT_ITEM},
  {"Escape", QUIT_INVENTORY},
};

#endif
