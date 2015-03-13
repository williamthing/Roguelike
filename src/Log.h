#ifndef LOG_H_
#define LOG_H_
#include <vector>
#include <iostream>

class Log {
  const int _size;
  int _next;
  int _initialize;
  std::vector<int> _log;

  public:
    Log(int size, int initialize);
    void append(int move);
    void print(char name, std::ostream& o) const;
};
#endif
