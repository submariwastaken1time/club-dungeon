#ifndef RENDERING_INCLUDES
#define RENDERING_INCLUDES

#include "ECS_init.hpp"
#include "global_entity_values.hpp"

#endif

#ifndef RENDERING
#define RENDERING

void render_character (int level, int x , int y, entt::entity &entity, 
entt::registry reg , tcod::console console) {
  TCOD_console_put_char(console, x ,y , reg.get<icon>(entity).icon)
}

#endif
