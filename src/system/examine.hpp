//examines hp

#include <stdlib.h>



void ExamineHP(entt::entity entity){
  // remember to add in an extra clause for the component
  if(!E_registry.valid(entity)){
    printf("Non valid entity/Component doesn't exist!");
  }
  else{
  auto get_hp = E_registry.get<hp>(entity);

  printf(get_hp);
  }
}
