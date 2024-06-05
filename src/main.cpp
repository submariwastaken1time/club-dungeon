#include <stdlib.h>
#include <libtcod.hpp>
#include <SDL.h>

#include "global_entity_values.hpp"
#include "system/examine.hpp"
#include "system/bump.hpp"
#include "entity/orc.hpp"
#include "rendering_init.hpp"
// where the main loop of the game is, the code in the header files are added here, with includes used
// to keep the code as modular as possible, think of the header files as a bin of lego pieces, and
// this is where you assemble them

int main(int argc, char* argv[]){
  auto console = tcod::Console{80, 25};  // Main console.

  // Configure the context.
  auto params = TCOD_ContextParams{};
  params.tcod_version = TCOD_COMPILEDVERSION;  // This is required.
  params.console = console.get();  // Derive the window size from the console size.
  params.window_title = "Libtcod Project";
  params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
  params.vsync = true;
  params.argc = argc;  // This allows some user-control of the context.
  params.argv = argv;

  // Tileset example using a Code Page 437 font.
  // "terminal8x8_gs_ro.png" must be in the working directory.
  // auto tileset = tcod::load_tilesheet("terminal8x8_gs_ro.png", {16, 16}, tcod::CHARMAP_CP437);
  // params.tileset = tileset.get();
  auto context = tcod::Context(params);

  while (1) {  // Game loop.
    TCOD_console_clear(console.get());
    tcod::print(console, {0, 0}, "Hello World", std::nullopt, std::nullopt);
    context.present(console);  // Updates the visible display.

    SDL_Event event;
    SDL_WaitEvent(nullptr);  // Optional, sleep until events are available.
    while (SDL_PollEvent(&event)) {
      context.convert_event_coordinates(event);// Optional, converts pixel coordinates into tile
                                               //coordinates.
      switch (event.type) {
        case SDL_QUIT:
          return 0;  // Exit.
      }
    }
  }
}
