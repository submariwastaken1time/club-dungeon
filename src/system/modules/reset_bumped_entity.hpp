#ifndef RESET_BUMPED_ENTITY_INCLUDES
#define RESET_BUMPED_ENTITY_INCLUDES

#include "../../ECS_init.hpp"
#include "../../states.hpp"

#endif

#ifndef RESET_BUMPED_ENTITY
#define RESET_BUMPED_ENTITY
void reset_bumped_component(entt::registry &reg, entt::entity entity) {
  reg.patch<bumped_into>(entity, [&](auto &b_into){b_into.bumped_ent = entt::null;});
}
#endif
