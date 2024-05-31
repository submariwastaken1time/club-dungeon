#include <stdlib.h>

#include "system/examine.hpp"
#include "system/bump.hpp"
#include "entity/orc.hpp"
#include "system/rendering.hpp"

// where the main loop of the game is, the code in the header files are added here, with includes used
// to keep the code as modular as possible, think of the header files as a bin of lego pieces, and
// this is where you assemble them

int main(){
  Create_Orc(E_registry);
  ExamineHP(Orc, E_registry);
}
