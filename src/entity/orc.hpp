#ifndef ORC_INCLUDES
#define ORC_INCLUDES

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

entt::entity Create_Orc(entt::registry &registry) {
  auto orc = registry.create();
  registry.emplace<name>(orc,"Orc");
  registry.emplace<pos>(orc, 0 , 0 );
  registry.emplace<icon>(orc, 'O');
  registry.emplace<fg>(orc, 0 , 0 , 0 );
  registry.emplace<hp>(orc, 0 );
  registry.emplace<atk>(orc, 0 );
  registry.emplace<xp>(orc, 0 );
  registry.emplace<AI>(orc, 0 );
  return orc;
}
