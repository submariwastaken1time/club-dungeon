#ifndef ENCHANT_SCROLL_INCLUDES
#define ENCHANT_SCROLL_INCLUDES
#include "../../ECS_init.hpp"
#include "../global_entity_values.hpp"
#endif

#ifndef ENCHANT_SCROLL
#define ENCHANT_SCROLL
void create_enchant_scroll(entt::registry &registry) {
  auto enchant_scroll = registry.create();
  registry.emplace<name>(enchant_scroll,"Enchant scroll");
  registry.emplace<pos>(enchant_scroll, 2 , 2 );
  registry.emplace<icon>(enchant_scroll, '?');
  registry.emplace<fg>(enchant_scroll, fg{255u , 255u , 255u} );
  registry.emplace<collision_tag>(enchant_scroll, true);
  registry.emplace<item>(enchant_scroll);
  registry.emplace<enchant>(enchant_scroll)
  return enchant_scroll;
}
#endif
