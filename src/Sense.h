#ifndef SENSE_H_
#define SENSE_H_

class Frame;

class Sense {
  Frame* _game_map;
  public:
    Sense(Frame* game_map);
    bool open_pos(int row, int col) const;
    int size() const;
};
#endif
