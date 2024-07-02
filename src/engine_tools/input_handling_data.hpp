#ifndef INPUT_HANDLING_DATA
#define INPUT_HANDLING_DATA

#include <unordered_map>
// the map used to convdert to the action dictionary
std::unordered_map<std::string, action_dictionary> key_bind_to_enum = {
  {"", NONE},
  {"Up", UP_MOVE},
  {"Down", DOWN_MOVE},
  {"Left", LEFT_MOVE},
  {"Right", RIGHT_MOVE}
};

#endif
