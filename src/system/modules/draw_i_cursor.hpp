#ifndef RENDER_I_CURSOR_INCLUDES
#define RENDER_I_CURSOR_INCLUDES
#include <libtcod.h>
#endif

#ifndef RENDER_I_CURSOR
#define RENDER_I_CURSOR
void render_i_cursor(int item_highlighted, tcod::Console &con) {
  int inven_w_offset = con.get_width() - 1;
  int inven_h_offset = con.get_height();
  tcod::draw_rect(con, { inven_w_offset , inven_h_offset - item_highlighted , 10 , 1 },
  0,{{0,0,0}},{{10,10,0}}, TCOD_BKGND_LIGHTEN );
}
#endif
