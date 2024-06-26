#ifndef EXAMINE_HP_INCLUDES // these are preprocessor directives to prevent conflicts with other files in
#define EXAMINE_HP_INCLUDES // compilation
//system header includes
#include <stdlib.h>
#include <iostream>
#include <format>
//source folder includes
#include "ECS_init.hpp"
#include "Global_entity_values.hpp"

#endif

#ifndef EXAMINE_HP
#define EXAMINE_HP

//examines hp
void examine_HP(entt::entity entity , entt::registry &registry){
  bool all = registry.all_of<hp,name>(entity);
  // checking if the entity is valid in the registry and if they have both an hp and name component
  if(!registry.valid(entity) || !all) {
    std::cout << "Non valid entity/Component doesn't exist!" << std::endl;
  }
  else {
  // if the components exists and the entity is valid, it gets passed here, where the hp is printed out
  // along with the name

  // getting the name and hp of said components, along with conversions to the needed types for
  // the printf function to work
  int get_HP = registry.get<hp>(entity).hp;
  std::string get_name = registry.get<name>(entity).name;


  std::cout << std::format("the {} has {} HP", get_name, get_HP);

  }
}
#endif
