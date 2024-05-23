/*pseudo code but:*/

void generate(floorID){
for(tiles.start : tiles.end){
  floor.data.current_tile[x,y] = rng([insert fixtures here])
  //insert special procgen logic after here for structures and what not
  //spawning enemies
  spawn_enemies(floorID)
  //spawning items
  spawn_items(floorID)
}
}

void spawn_enemies(floorID){
  enemy1.make_new = enemyform(blah,pos(x,y),blah,blah)
}
//same with spawning items too
