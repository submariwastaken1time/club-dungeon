#ifndef RENDER_RECTANGLE_INCLUDES
#define RENDER_RECTANGLE_INCLUDES

#include <libtcod.hpp>

#include "../global_entity_values.hpp"

#endif

#ifndef RENDER_RECTANGLE
#define RENDER_RECTANGLE

void render_inventory(tcod::Console &con, entt::registry inven_cont) {
  int inven_w_offset = con.w - 1;
  int inven_h_offset = con.h;
  tcod::draw_frame(con, { inven_w_offset , inven_h_offset , 10 , con.h },
  {'1','2','3','4','5','6','7','8'}, {{255,255,255}},{{10,10,10}} );

  auto inven_elements = inven_cont.view<name>;

  for (entt::entity inven_element : inven_elements) {
    auto item_name = reg.get<name>.name;

    tcod::print(con,{inven_w_offset,inven_h_offset},item_name, {{255,255,255}}, {{10,0,0}},
    TCOD_LEFT, TCOD_BKGND_LIGHTEN);
  }
}

#endif
