#ifndef TREASURE_H_
#define TREASURE_H_
#include "Character.h"

class Treasure : public Character {
  public:
    Treasure();
    Treasure(int row_0, int col_0, int logsize=10);
    char symbol() const;
    int get_move();
};
#endif
