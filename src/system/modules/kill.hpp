#ifndef KILL_INCLUDES
#define KILL_INCLUDES
#include <iostream>

#include "../../ECS_init.hpp"
#include "../../states.hpp"
#endif

#ifndef KILL
#define KILL
void kill(entt::registry &reg, entt::entity entity) {
  if (G_state == ingame && reg.all_of<hp>(entity)) {
  auto entity_name = reg.get<name>(entity).name;
  if (reg.get<hp>(entity).hp < 0) {
    reg.destroy(entity);
    std::cout << "The " << entity_name << " dies!" << std::endl;
  } else {
    #ifdef debug_mode
    std::cout << "no one died" << std::endl;
    #endif
  }
  }
}
#endif
