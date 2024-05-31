#ifndef ORC
#define ORC

#include "ECS_init.hpp"
#include "Global_entity_values.hpp"

#endif

/*
(*) monster/entity table:
ID | name | position | character | foreground color | hp | atk | xp | AI
*/

// creates a blank orc with blank values
// more changes to the orc can be done with the in built functions that are in entt itself, but this is
// just a blank canvas

auto Create_Orc(entt::registry &registry) {
  auto Orc = registry.create();
  registry.emplace<name>(Orc,"Orc");
  registry.emplace<pos>(Orc, 0 , 0 );
  registry.emplace<icon>(Orc, 'O');
  registry.emplace<fg>(Orc, 0 , 0 , 0 );
  registry.emplace<hp>(Orc, 0 );
  registry.emplace<atk>(Orc, 0 );
  registry.emplace<xp>(Orc, 0 );
  registry.emplace<AI>(Orc, 0 );
  return Orc;
}
