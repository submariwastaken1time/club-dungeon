#ifndef EXAMINE
#define EXAMINE
//examines hp
#include <stdlib.h>

#include "ECS_init.hpp"
#include "Global_entity_values.hpp"

void ExamineHP(entt::entity entity; entt::registry registry){
  // remember to add in an extra clause for the component
  bool all = registry.all_of<struct hp, struct name>(entity)

  if(!registry.valid(entity) && !all) {
    printf("Non valid entity/Component doesn't exist!");
  }
  else{
  auto get_hp = registry.get<struct hp>(entity);
  auto get_name = registry.get<struct name>(entity);

  std::cout << get_name; std::cout << "has"; std::cout << get_hp; std::cout << "HP";
  }
}

#endif
