
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Scorecard.h"
#include "Log.h"

class Character {
	int _row, _col;
  Log* _log;
public:
	// Create a character
	Character(int row_0, int col_0, int logsize = 10);
	// Change the character position
	void pos(int row_0, int col_0);
	// Get character's row (y) position
	int row() const;
	// Get character's col (x) position
	int col() const;

  int get_move_logged();
  virtual void score(Scorecard& sc);
  virtual char symbol() const = 0;
  virtual ~Character();
  void print_log(std::ostream& o) const;
  
protected:
  virtual int get_move() = 0;
};

#endif
