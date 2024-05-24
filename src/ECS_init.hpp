#include <entt/entt.hpp>

entt::registry E_registry; // monster/entity registry

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
