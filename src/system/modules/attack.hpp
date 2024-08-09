#ifndef ATTACK_INCLUDES
#define ATTACK_INCLUDES

#include "ECS_init.hpp"

#endif

#ifndef ATTACK
#define ATTACK

void attack(entt::entity attacker, entt::registry reg, entt::entity attacked) {
  auto attack = reg.get(attacker)<atk>.atk;
  auto bumped = reg.get(attacker)<bumped_tag>.bumped_tag;
  auto atkd_has_HP = reg.all_of<hp>(attacked);

  if (bumped && atkd_has_HP) {
    reg.patch<HP>(attacked, [&](auto &HP) {HP.HP = HP.HP - attack;});
  }
}

#endif
