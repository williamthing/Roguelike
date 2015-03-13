#include "Log.h"

Log::Log(int size, int initialize) 
  : _size(size)
  , _next(0)
  , _initialize(initialize)
  , _log(size) {
    for (int i=0; i<_size; i++) {
      _log[i] = initialize;
    }
  }

void Log::append(int move) {
  if (_next < _size) {
    _log[_next++] = move;
  }
} 

void Log::print(char name, std::ostream& o) const {
  o << name << ": ";
  for (int i=0; i<_size; i++) {
    if (_log[i] == _initialize) break;
    o << _log[i] << ", ";
  }
  o << std::endl;
}
