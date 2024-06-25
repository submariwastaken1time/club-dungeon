#include <stdlib.h>
#include <libtcod.hpp>
#include <SDL.h>

#include "global_entity_values.hpp"

#include "system/examine.hpp"
#include "system/bump.hpp"
#include "system/render_character.hpp"
#include "entity/orc.hpp"
#include "entity/player.hpp"
#include "engine_tools/state_manager.hpp"
#include "engine_tools/input_handling.hpp"
#include "engine_tools/rebinding.hpp"

// where the main loop of the game is, the code in the header files are added here, with includes used
// to keep the code as modular as possible, think of the header files as a bin of lego pieces, and
// this is where you assemble them

int main(int argc, char* argv[]){
  // Configure the context.
  auto params = TCOD_ContextParams{};
  params.tcod_version = TCOD_COMPILEDVERSION;  // This is required.
  params.window_title = "Libtcod Project";
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.vsync = true;
  params.argc = argc;  // This allows some user-control of the context.
  params.argv = argv;
  // Tileset example using a Code Page 437 font.
  // "terminal8x8_gs_ro.png" must be in the working directory.
  auto tileset = tcod::load_tilesheet("E://club-dungeon/Anikki_square_16x16.png", {16, 16},
  tcod::CHARMAP_CP437);
  params.tileset = tileset.get();
  auto context = tcod::Context(params);

  while (G_state != quit) {

  auto console = context.new_console();

  static const auto viewport_options = TCOD_ViewportOptions{
    .tcod_version = TCOD_COMPILEDVERSION,
    .keep_aspect = true,
    .integer_scaling = true,
    .clear_color = {0,0,0,255},
    .align_x = 0.5,
    .align_y = 0.5,
  };

  render_character(create_player(E_registry), E_registry, console, {0,0,0});


  // auto console = tcod::Console{80,50};
  tcod::print(console, {0, 0}, "Hello World", {{255, 255, 255}}, {{0, 0, 0}});
  std::cout << TCOD_get_error();
  context.present(console,viewport_options);

    // context.present(console);
    SDL_Event event;
    while (SDL_PollEvent(&event)){
      if(event.key.state == SDL_PRESSED){
        key_to_action(SDL_GetScancodeName(event.key.keysym.scancode));
        std::cout << game_actions.y_move;
      }
    }
    SDL_WaitEvent(nullptr);
  }
  return 0;
}
