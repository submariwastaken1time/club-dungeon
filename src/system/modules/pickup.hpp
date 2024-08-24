#ifndef PICKUP_INCLUDES
#define PICKUP_INCLUDES

#include "../../global_entity_values.hpp"
#include "../../ECS_init.hpp"

#endif

#ifndef PICKUP
#define PICKUP

void pickup(entt::registry &reg, entt::entity item) {
  reg.emplace_or_replace<in_inventory>(item);
}

#endif
