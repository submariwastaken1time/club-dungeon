#ifndef RENDER_CHAR_INCLUDES
#define RENDER_CHAR_INCLUDES
#include <iostream>

#include "../../ECS_init.hpp"
#include "../../global_entity_values.hpp"
#endif

#ifndef RENDER_CHAR
#define RENDER_CHAR

void render_character(entt::entity entity, entt::registry &reg , tcod::Console &console,
TCOD_ColorRGB bg_color ) {

uint32_t code_point = reg.get<icon>(entity).icon;
int x = reg.get<pos>(entity).pos_x;
int y = reg.get<pos>(entity).pos_y;
TCOD_ColorRGB fg_color = {reg.get<fg>(entity).fg_r, reg.get<fg>(entity).fg_b, reg.get<fg>(entity).fg_b};

if (console.in_bounds({x, y})) {
  auto& tile = console.at({x, y});
  tile.ch = code_point;
  tile.fg = fg_color;
  tile.bg = bg_color;
} else {}

}

#endif
