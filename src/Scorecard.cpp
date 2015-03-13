#include <iostream>
#include <sstream>
#include "Scorecard.h"

Scorecard::Scorecard() 
  : _score_mons(0)
  , _score_player(0) { }

const char* Scorecard::get_score() const {
  std::stringstream ss;
  ss << std::endl
    << "GAME OVER: (press any key to quit)" << std::endl
    << "Player: " << this->_score_player << std::endl
     << "Monster: " << this->_score_mons << std::endl;
  return ss.str().c_str();
}

void Scorecard::player_scores() {
  this->_score_player+=1;
}

void Scorecard::monster_scores() {
  this->_score_mons+=1;
}
