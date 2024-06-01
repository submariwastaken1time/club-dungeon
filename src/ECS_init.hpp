#ifndef ECS_INIT_INCLUDES
#define ECS_INIT_INCLUDES

#include <entt/entt.hpp>

//setup for the registry and ECS component of the engine

entt::registry E_registry; // monster/entity registry, possibly also the registry for most game objects

#endif

/*
gonna lay out the plans for the registry here for later reference:

// (*) monster/entity table:
// ID | name | position | character | foreground color | hp | atk | xp | AI
// (*) fixture table:
// ID | name | character | position | foreground color | collision
// (*) floor table:
// ID | data (array)

(!) most of this bullshit is rather dumb anyways
*/
