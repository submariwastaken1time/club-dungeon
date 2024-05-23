  // for (int repeats{0}; repeats < 20; ++repeats) {
  //   auto& [monster_id, monster] = *new_actor(world);
  //   monster.pos = pop_random(floor_tiles, world.rng);
  //   monster.name = "orc";
  //   monster.ch = 'o';
  //   monster.fg = {63, 127, 63};
  //   monster.stats.max_hp = monster.stats.hp = 10;
  //   monster.stats.attack = 3;
  //   monster.stats.xp = 35;
  //   monster.ai = std::make_unique<action::BasicAI>();
  //   world.schedule.push_back(monster_id);
  // }
#include <ECS_registry_init.hpp>
auto orc = registry.create()
registry.emplace<position>(orc, 0.,0.)
