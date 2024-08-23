
void init_game(entt::registry &reg) {
  create_orc(reg);
  create_player(reg);
  T_set_orc_pos(reg);
  set_ingame();
}
