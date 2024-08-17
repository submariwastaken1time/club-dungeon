#ifndef SET_NEARBY_TOOLS_INCLUDES
#define SET_NEARBY_TOOLS_INCLUDES

#include "ECS_init.hpp"

#endif

#ifndef SET_NEARBY_TOOLS
#define SET_NEARBY_TOOLS
void set_nearby_to_entity(entt::registry reg, entt:entity entity) {

  auto entity_pos = reg.get<pos>(entity);

  std::unordered_map< int, int, bool> nearby_map = {
    {entity_pos.pos_x, entity_pos.pos_y + 1, true},
    {entity_pos.pos_x, entity_pos.pos_y - 1, true},
    {entity_pos.pos_x + 1, entity_pos.pos_y, true},
    {entity_pos.pos_x - 1, entity_pos.pos_y, true},
    {entity_pos.pos_x - 1, entity_pos.pos_y + 1, true},
    {entity_pos.pos_x + 1, entity_pos.pos_y + 1, true},
    {entity_pos.pos_x - 1, entity_pos.pos_y - 1, true},
    {entity_pos.pos_x + 1, entity_pos.pos_y - 1, true}
  }
}
#endif
