#ifndef MAP_ENTITY_H_
#define MAP_ENTITY_H_

class MapEntity {
  public:
    virtual char symbol() const = 0;
    virtual ~MapEntity();
};

#endif
