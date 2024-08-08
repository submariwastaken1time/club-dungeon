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
  render_entity(E_registry, console, {0,0,0});
  context.present(console,viewport_options);
    SDL_Event event;
    while (SDL_PollEvent(&event)){
      if(event.key.state == SDL_PRESSED){
        update_player(E_registry, SDL_GetScancodeName(event.key.keysym.scancode));
        update_monsters(E_registry);
      }
    }
    SDL_WaitEvent(nullptr);
}
