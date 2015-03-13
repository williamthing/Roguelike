#include "Sense.h"
#include "Frame.h"

Sense::Sense(Frame* game_map)
  : _game_map(game_map) { }

bool Sense::open_pos(int row, int col) const {
  return _game_map->target_position(row, col);
}

int Sense::size() const {
  return _game_map->height()*_game_map->height() + _game_map->width()*_game_map->width();
}
