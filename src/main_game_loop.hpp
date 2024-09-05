#ifndef debug_move
#define debug_move
#endif
#ifndef MAIN_GAME_LOOP
#define MAIN_GAME_LOOP

void main_loop() {
  auto console = context.new_console();
  static const auto viewport_options = TCOD_ViewportOptions{
    .tcod_version = TCOD_COMPILEDVERSION,
    .keep_aspect = true,
    .integer_scaling = true,
    .clear_color = {0,0,0,255},
    .align_x = 0.5,
    .align_y = 0.5,
  };
  switch (G_state) {
    case ingame: {render_game(E_registry, console, {0,0,0});} break;
    case inventory_screen: {} break;
    case pause_menu: {} break;
    case menu_1: {} break;
  }
  context.present(console,viewport_options);
    SDL_Event event;
    while (SDL_PollEvent(&event)){
      if(event.key.state == SDL_PRESSED){
        auto get_key = SDL_GetScancodeName(event.key.keysym.scancode);
        #ifdef debug_move
        std::cout << SDL_GetScancodeName(event.key.keysym.scancode) << std::endl;
        #endif
        switch (G_state) {
          case ingame: {prompt_player_ingame(E_registry, get_key); update_ingame(E_registry);} break;
          case inventory_screen: {update_inventory(E_registry);} break;
          case pause_menu: {} break;
          case menu_1: {} break;
        }
      }
    }
    SDL_WaitEvent(nullptr);
  std::atexit(SDL_Quit);
}
#endif
