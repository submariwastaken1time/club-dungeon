#ifndef ATTACK_INCLUDES
#define ATTACK_INCLUDES

#include <iostream>

#include "../../ECS_init.hpp"

#endif

#ifndef ATTACK
#define ATTACK

void attack(entt::entity attacker, entt::registry &reg, entt::entity attacked) {
  auto atkd_HP = reg.get<hp>(attacked).hp;
  auto atkr_atk = reg.get<atk>(attacker).atk;

  reg.patch<hp>(attacked,[&](auto &HP){HP.hp = atkd_HP - atkr_atk;});
  #ifdef debug_mode
  std::cout << std::format("damage done is {}", atkr_atk) << std::endl;
  #endif
}

#endif
