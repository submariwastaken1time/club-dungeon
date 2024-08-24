#ifndef RENDER_GAME_INCLUDES
#define RENDER_GAME_INCLUDES
#include <iostream>
#include "../global_entity_values.hpp"
#include "modules/render_character.hpp"
#include "../states.hpp"
#include "../engine_tools/render_inventory.hpp"
#include "../engine_tools/render_i_cursor.hpp"

#endif

#ifndef RENDER_GAME
#define RENDER_GAME

void render_game(entt::registry &reg, tcod::Console &con, TCOD_ColorRGB bg_color) {
  if (G_state == ingame) {
    auto view_renderables = reg.view<icon, pos, fg>();
    con.clear();
    for (entt::entity entity : view_renderables) {
      render_character(entity, reg, con, bg_color);
    }
  }
  if (G_state == inventory_screen) {
    auto view_player = reg.view<player_marker>();
    for (auto entity : view_player) {
      auto is_open_i_button_pressed = reg.get<actions>(entity).actions.open_inventory;
      if (is_open_i_button_pressed) {
        auto item_highlighted = reg.get<actions>(entity).actions.i_highlight_char;
        render_inventory(con,reg);
        render_i_cursor(item_highlighted,con);
      }
    }
  }
}
#endif
