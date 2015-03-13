#ifndef BABY_MONSTER_H_
#define BABY_MONSTER_H_
#include "Monster.h"

class BabyMonster : public Monster {
	Sense* _sense;
	Character* _prey;
	int _movecounter;
	public:
	BabyMonster(int row_0, int col_0, Sense* s, Character* prey, int logsize = 10);
	int get_move();
	char symbol() const;
};
#endif
