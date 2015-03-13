#ifndef PLAYER_H_
#define PLAYER_H_

#include "Character.h"

class Player : public Character {
  public:
    Player(int row0, int col0, int logsize=10);
    int get_move();
    void score(Scorecard& sc);
    char symbol() const;
};
#endif
