#ifndef RENDER_GAME_INCLUDES
#define RENDER_GAME_INCLUDES

#include "global_entity_values.hpp"
#include "system/modules/render_character.hpp"

#endif

#ifndef RENDER_GAME
#define RENDER_GAME

void render_entity(entt::registry &reg, tcod::Console &con, TCOD_ColorRGB bg_color) {
  auto view_renderables = reg.view<icon, pos, fg>();

  for (entt::entity entity : view_renderables) {
    con.clear();
    render_character(entity, reg, con, bg_color);

  }
}

#endif
