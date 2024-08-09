#ifndef ATTACK_INCLUDES
#define ATTACK_INCLUDES

#include "ECS_init.hpp"

#endif

#ifndef ATTACK
#define ATTACK

void attack(entt::entity attacker, entt::registry reg, entt::entity attacked) {
  auto attack = reg.get<atk>(attacker).atk;
  auto bumped = reg.get<bumped_tag>(attacker).bumped_tag;
  auto atkd_has_HP = reg.all_of<hp>(attacked);

  if (bumped && atkd_has_HP) {
    reg.patch<hp>(attacked, [&](auto &hp) {hp.hp = hp.hp - attack;});
  }
}

#endif
