#ifndef MONSTER_H_
#define MONSTER_H_
#include "Character.h"
#include "Sense.h"

class Monster : public Character {
    Sense* _sense;
    Character* _prey;
  public:
    Monster(int row_0, int col_0, Sense* s, Character* prey, int logsize = 10);
    int get_move();
    void score(Scorecard& sc);
    char symbol() const;
};
#endif
