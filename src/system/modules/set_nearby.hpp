// currently shelving this for now
#ifndef SET_NEARBY_INCLUDES
#define SET_NEARBY_INCLUDES

#include <iostream>

#include "ECS_init.hpp"
#include "engine_tools/set_nearby_tools.hpp"

#endif

#ifndef SET_NEARBY
#define SET_NEARBY
void set_nearby(entt::registry &reg) {

  auto any_ent_pos = reg.view<pos>();
  for (entt:entity entity : any_ent_pos) {

    int x = reg.get<pos>(entity).pos_x;
    int y = reg.get<pos>(entity).pos_y;

    switch(nearby_map[x,y]) {
      case true: {
        // add entity to registry
      }
      default: {
        #ifdef debug_mode
        std::cout << "Exception occured! The nearby entity was not added to the nearby registry"
        #endif
      }
    }
  }
}
#endif
