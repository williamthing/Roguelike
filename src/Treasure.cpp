
#include "Treasure.h"
#include "Directions.h"

Treasure::Treasure() 
  : Character(-1, -1, 1) { }

Treasure::Treasure(int row_0, int col_0, int logsize)
: Character(row_0, col_0, logsize) { }

char Treasure::symbol() const {
  return '$';
}

int Treasure::get_move() {
  return Directions::NONE;
}
