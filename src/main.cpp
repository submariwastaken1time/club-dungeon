#include "main.hpp"
#include "SDL2/SDL.h"

Engine engine(80,50);
SDL_Event event;

int main() {
  bool quit = false;
  while (quit = false) {
      while(SDL_PollEvent(&event) >= 0){
     if(event.type == SDL_QUIT){
     quit = true;
     }
    engine.update();
    engine.render();
		TCOD_console_flush();
   }
  }
    return 0;
}
