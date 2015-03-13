
#ifndef SCORE_H_
#define SCORE_H_

class Scorecard {
  private:
    int _score_mons;
    int _score_player;
    char _score_str[1024];

  public:
    Scorecard();
    const char* get_score() const;
    void monster_scores();
    void player_scores();
};
#endif
