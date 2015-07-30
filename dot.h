#ifndef __DOT_H__
#define __DOT_H__

#include "coordinate.h"

class Dot {
  public:
    Dot();
  
    Coordinate position;
    bool is_spawned();
    bool is_ripe();

    int get_age();

    void clear();
    void spawn(Coordinate coordinate);
    void ripen();

  private:
    int m_age;
};

#endif
