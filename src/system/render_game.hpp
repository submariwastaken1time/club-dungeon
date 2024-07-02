#ifndef RENDER_GAME_INCLUDES
#define RENDER_GAME_INCLUDES

#include "global_entity_values.hpp"
#include "system/modules/render_character.hpp"

#endif

#ifndef RENDER_GAME
#define RENDER_GAME

void render_entity(entt::registry &reg, tcod::Console &con, TCOD_ColorRGB bg_color) {
  auto view_renderables = reg.view<icon, pos, fg>(); // retrieve all the renderables to feed them to
  // the rendering function

  for (entt::entity entity : view_renderables) { // iterating through the view to retrieve an entity
    con.clear(); // clears the console from the last draw to prevent this from becoming a bad game of
    // snake
    render_character(entity, reg, con, bg_color);

  }
}

#endif
