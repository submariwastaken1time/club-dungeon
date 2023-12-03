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

  while (g_quit == false) {
    while (SDL_PollEvent()) {
      const SDL_Event sdl_event;
      TCOD_mouse_t mouse_event;
      TCOD_key_t key_event;
      tcod::sdl2::process_event(sdl_event, mouse_event) tcod::sdl2::process_event(sdl_event, key_event);
    }
    engine.update();
    engine.render();
    TCODConsole::flush();
  }

  return 0;
}
