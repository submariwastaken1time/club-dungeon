// a way to turn on/off debug printing and other useful features for debugging

// #ifndef debug_mode
// #define debug_mode
// #endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif  __EMSCRIPTEN__

#include <stdlib.h>
#include <libtcod.hpp>
#include <SDL.h>

#include "global_entity_values.hpp"

#include "system/render_game.hpp"
#include "system/update_game.hpp"
#include "system/modules/examine_HP.hpp"
// #include "system/modules/bump_test.hpp"
#include "system/modules/render_character.hpp"
#include "system/modules/move.hpp"
#include "system/modules/input_handling.hpp"
#include "entity/player.hpp"
#include "entity/orc.hpp"
#include "engine_tools/state_manager.hpp"
#include "engine_tools/rebinding.hpp"

auto params = TCOD_ContextParams{};
auto context = tcod::Context(params);

#include "init_game.hpp"
#include "main_game_loop.hpp"
/*
where the meat and potatoes of the game is, the code in the header files are added here, with
includes used to keep the code as modular as possible, think of the header files as a bin of lego
pieces, and this is where you assemble them
*/

int main(int argc, char* argv[]) {
    // Configure the context.
  params.tcod_version = TCOD_COMPILEDVERSION;  // This is required.
  params.window_title = "Libtcod Project";
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.vsync = true;
  params.argc = argc;  // This allows some user-control of the context.
  params.argv = argv;
  auto tileset = tcod::load_tilesheet("E://club-dungeon/Anikki_square_16x16.png", {16, 16},
  tcod::CHARMAP_CP437);
  params.tileset = tileset.get();
    init_game();
  #ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(main_loop, 0, 0);
  #else
  while (G_state != quit){ main_loop();}
  #endif
  return 0;
}
