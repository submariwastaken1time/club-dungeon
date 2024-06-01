#ifndef EXAMINE_INCLUDES // these are preprocessor directives to prevent conflicts with other files in
#define EXAMINE_INCLUDES // compilation

#include <stdlib.h>
#include <iostream>

#include "ECS_init.hpp"
#include "Global_entity_values.hpp"

#endif

//examines hp
void ExamineHP(entt::entity &entity , entt::registry &registry){
  bool all = registry.all_of<hp,name>(entity);
  // checking if the entity is valid in the registry and if they have both an hp and name component
  if(!registry.valid(entity) && !all) {
    printf("Non valid entity/Component doesn't exist!");
  }
  else {
  // if the components exists and the entity is valid, it gets passed here, where the hp is printed out
  // along with the name

  // getting the name and hp of said components, along with conversions to the needed types for
  // the printf function to work
  int get_hp = registry.get<hp>(entity).hp;
  int *p_get_hp = &get_hp; //casting to integer pointer for printf
  std::string get_name = registry.get<name>(entity).name;
  const char *c_get_name = get_name.c_str(); // casting to c style string pointer for printf

  printf("the %s has %n HP" , c_get_name , p_get_hp);
  }
}
