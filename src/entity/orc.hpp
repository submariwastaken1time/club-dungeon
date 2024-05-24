#include <ECS_init.hpp>

/*
(*) monster/entity table:
ID | name | position | character | foreground color | hp | atk | xp | AI
*/

void create_troll() {
  orc = registry.create();
  E_registry.emplace<name>(orc, Orc.);
  E_registry.emplace<pos>(orc, 0. , 0.);
  E_registry.emplace<chr>(orc, O.);
  E_registry.emplace<fg>(orc, 0.,0.,0.,);
  E_registry.emplace<hp>(orc, 0.);
  E_registry.emplace<atk>(orc, 0.);
  E_registry.emplace<xp>(orc, 0.);
  E_registry.emplace<AI>(orc, 0.)
}
