#include "main.hpp"
#include "SDL.h"

extern "C"

Engine engine(80, 50);

bool g_quit = false;

static int QuitFunction(void* userdata, SDL_Event* event) {
  if (event->type == SDL_QUIT) {
    g_quit = true;
  }
  return 0;
}

int main(int argc, char* args[]) {
  SDL_AddEventWatch(QuitFunction, NULL);

  SDL_Event player_input;

  while (g_quit == false) {
    while (SDL_PollEvent(&player_input)) {
      const SDL_Event player_input_processing = player_input;
      TCOD_mouse_t mouse_event;
      TCOD_key_t key_event;
      TCOD_mouse_t &mouse_event_processed = mouse_event;
      TCOD_key_t &key_event_processed = key_event;
      tcod::sdl2::process_event(player_input_processing, mouse_event_processed);
      tcod::sdl2::process_event(player_input_processing, key_event_processed);

    }
    engine.update();
    engine.render();
    TCODConsole::flush();
  }

  return 0;
}
