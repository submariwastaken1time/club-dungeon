#ifndef REBINDING_INCLUDES
#define REBINDING_INCLUDES

#include <string>

#include "input_handling_data.hpp"

#endif

#ifndef REBINDING
#define REBINDING

void rebinding(std::string key, action_dictionary target) {
  key_bind_to_action[key] = target;
}

#endif
