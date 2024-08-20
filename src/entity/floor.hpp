#ifndef FLOOR_INCLUDES
#define FLOOR_INCLUDES
#include "../ECS_init.hpp"
#endif

#ifndef FLOOR
#define FLOOR
entt::entity create_floor(entt::registry &reg) {
  auto floor = registry.create();
  registry.emplace<name>(floor, "Floor");
  registry.emplace<pos>(floor, 0 , 0 , 0);
  registry.emplace<icon>(floor, '.');
  registry.emplace<fg>(floor, fg{255u , 255u , 255u} );
  registry.emplace<collision_tag>(floor, false);
  return floor;
}
#endif
