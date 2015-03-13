#include "Character.h"
#include "Directions.h"
#include <iostream>

// Create a character
Character::Character(int row_0, int col_0, int logsize) 
  : _row(row_0)
  , _col(col_0)
  , _log(new Log(logsize, (int)Directions::QUIT)) { }

// Change the character position
void Character::pos(int row_0, int col_0) {
	_row = row_0;
	_col = col_0;
}

// Get character's row (y) position
int Character::row() const {
	return _row;
}

// Get character's col (x) position
int Character::col() const {
	return _col;
}

void Character::score(Scorecard& sc) {
  // do nothing (leave this blank)
}

int Character::get_move_logged() {
  int dir = get_move();
  _log->append(dir);
  return dir;
}

void Character::print_log(std::ostream& o) const {
  _log->print(this->symbol(), o);
}

Character::~Character() {
  delete _log;
}

