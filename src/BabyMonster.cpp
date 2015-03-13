#include "BabyMonster.h"
#include "Directions.h"  
#include <cmath>

BabyMonster::BabyMonster(int row_0, int col_0, Sense* s, Character* prey, int logsize)
    : Monster(row_0, col_0, s, prey, logsize)
	 , _sense(s)
	 , _prey(prey) 
    , _movecounter(0) {
	 }

int BabyMonster::get_move() {
	 if (_movecounter != 1) {
		 _movecounter++;
		 return Monster::get_move();
	 } else {
		 _movecounter--;
		 return Directions::NONE;
	 }
}

char BabyMonster::symbol() const {
	return 'm';
}
	
