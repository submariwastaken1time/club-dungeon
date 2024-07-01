#ifndef BUMP_TEST_INCLUDE
#define BUMP_TEST_INCLUDE

#include <stdlib.h>
#include "ECS_init.hpp"
#endif

#ifndef BUMP_TEST
#define BUMP_TEST

// the function used to determine whether to move or bump/attack/interact into/with things
// might pair this with movement to keep the code compact
void bump_test(entt::entity entity, entt::registry &reg, unsigned int x_to_be_tested,
unsigned int y_to_be_tested) {

}
#endif
