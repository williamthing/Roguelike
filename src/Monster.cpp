#include "Monster.h"
#include "Directions.h"
#include <cmath>

Monster::Monster(int row_0, int col_0, Sense* s, Character* prey, int logsize) 
  : Character(row_0, col_0, logsize)
  , _sense(s)
  , _prey(prey) {
  }

// Moves based on what results in smallest distance to its prey
int Monster::get_move() {
		// Try to move left
		int dir = -1, score = _sense->size(), dist = -1;
		if( _sense->open_pos(this->row(), this->col() - 1)) {
			dist = std::pow(_prey->row() - this->row(),2) + std::pow(_prey->col() - (this->col() - 1),2);
			if(score > dist) {
				score = dist;
				dir = Directions::LEFT;
			}
		}
		// Try to move right
		if( _sense->open_pos(this->row(), this->col() + 1)) {
			dist = std::pow(_prey->row() - this->row(),2) + std::pow(_prey->col() - (this->col() + 1),2);
			if(score > dist) {
				score = dist;
				dir = Directions::RIGHT;
			}
		}
		// Try to move up
		if( _sense->open_pos(this->row() - 1, this->col())) {
			dist = std::pow(_prey->row() - (this->row() - 1),2) + std::pow(_prey->col() - this->col(),2);
			if(score > dist) {
				score = dist;
				dir = Directions::UP;
			}
		}
		// Try to move down
		if( _sense->open_pos(this->row() + 1, this->col())) {
			dist = std::pow(_prey->row() - (this->row() + 1),2) + std::pow(_prey->col() - this->col(),2);
			if(score > dist) {
				score = dist;
				dir = Directions::DOWN;
			}
		}

    return dir;
}

char Monster::symbol() const {
  return 'M';
}

void Monster::score(Scorecard& sc) {
  sc.monster_scores();
}
