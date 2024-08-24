#ifndef LIFE_POT_INCLUDES
#define LIFE_POT_INCLUDES
#include "../../ECS_init.hpp"
#include "../../global_entity_values.hpp"
#endif

#ifndef LIFE_POT
#define LIFE_POT

void create_life_pot(entt::registry &registry) {
  auto life_pot = registry.create();
  registry.emplace<name>(life_pot,"Life potion");
  registry.emplace<pos>(life_pot, 3 , 2 );
  registry.emplace<icon>(life_pot, '!');
  registry.emplace<fg>(life_pot, fg{255u , 255u , 255u} );
  registry.emplace<collision_tag>(life_pot, true);
  registry.emplace<item>(life_pot);
  registry.emplace<heal>(life_pot, 100);
  return enchant_scroll;
}

#endif
