// currently shelving this for now
#ifndef SET_NEARBY_INCLUDES
#define SET_NEARBY_INCLUDES

#include "ECS_init.hpp"
#include "engine_tools/set_nearby_tools.hpp"

#endif

#ifndef SET_NEARBY
#define SET_NEARBY
void set_nearby(entt::registry &reg) {
  auto any_ent_pos = reg.view<pos>();
  for (entt:entity entity : any_ent_pos) {
    switch(reg.get<pos>)
  }
}
#endif
