for (int repeats{0}; repeats < 4; ++repeats) {
    auto& [monster_id, monster] = *new_actor(world);
    monster.pos = pop_random(floor_tiles, world.rng);
    monster.name = "troll";
    monster.ch = 'T';
    monster.fg = tcod::ColorRGB{0, 127, 0};
    monster.stats.max_hp = monster.stats.hp = 16;
    monster.stats.defense = 1;
    monster.stats.attack = 4;
    monster.stats.xp = 100;
    monster.ai = std::make_unique<action::BasicAI>();
    world.schedule.push_back(monster_id);
  }
