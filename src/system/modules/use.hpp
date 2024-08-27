#ifndef USE_INCLUDES
#define USE_INCLUDES
#include <iostream>

#include "../../ECS_init.hpp"
#include "../../global_entity_values.hpp"
#endif

#ifndef USE
#define USE
void use(entt::registry &reg, entt::entity entity, entt::entity item) {
  if(reg.all_of<heal>(item)) {
    auto heal_amount = reg.get<heal>(item).amount;
    reg.patch<hp>(entity, [&](auto &hp) {hp.hp = hp.hp + heal_amount;});
  } else if (reg.all_of<enchant>(item)) {
    reg.patch<atk>(entity, [&](auto &atk) {atk.atk = atk.atk + 10;});
  } else {
    #ifdef debug_mode
    std::cout << "nothing used" << std::endl;
    #endif
  }
}
#endif
