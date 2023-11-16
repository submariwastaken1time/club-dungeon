#include "main.hpp"
#include "SDL.h"
extern "C"

Engine engine(80,50);
bool g_quit = false;

static int MyEventFunction(void *userdata, SDL_Event *event) {
    if( event->type == SDL_QUIT){
    g_quit = true;
    }
    return 0;
}

int main(int argc, char *args[]) {
   while (g_quit == false) {
     engine.update();
     engine.render();
		 TCOD_console_flush();
   }
  SDL_AddEventWatch( MyEventFunction , NULL);
return 0;
}
