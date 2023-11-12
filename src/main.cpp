#include "main.hpp"

Engine engine(80,50);

int main(int argc, char *args[]) {
  SDL_Event event;
  bool quit = false;
  while (quit == false) {
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
