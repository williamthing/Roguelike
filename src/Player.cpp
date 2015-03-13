#include <ncurses.h>
#include "Directions.h"
#include "Player.h"

Player::Player(int row0, int col0, int logsize) 
  : Character(row0, col0, logsize) { }

int Player::get_move() {
		int ch = getch();

		// Main character movements
		if(ch == KEY_LEFT) {
      return Directions::LEFT;
		}
		else if(ch == KEY_RIGHT) {
      return Directions::RIGHT;
		}
		else if(ch == KEY_UP) {
      return Directions::UP;
		}
		else if(ch == KEY_DOWN) {
      return Directions::DOWN;
		}
		else if(ch == 'q' || ch == 'Q') {
      return Directions::QUIT;
		}
    return Directions::NONE;
}

char Player::symbol() const {
  return '@';
}

void Player::score(Scorecard& s) {
  s.player_scores();
}
