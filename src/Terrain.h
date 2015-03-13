#ifndef TERRAIN_H_
#define TERRAIN_H_

#include "MapEntity.h"

class Water : public MapEntity {
  public:
  char symbol() const;
};
class Plain : public MapEntity {
  public:
  char symbol() const;
};
class Mountain : public MapEntity {
  public:
  char symbol() const;
};
class Snow : public MapEntity {
  public:
  char symbol() const;
};


#endif
