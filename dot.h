#ifndef __DOT_H__
#define __DOT_H__

#include "coordinate.h"

class Dot {
  public:
    Dot();
  
    Coordinate position;
    bool is_spawned();
    bool is_ripe();

    void clear();
    void spawn(Coordinate coordinate);
    void ripen();

  private:
    bool m_is_spawned;
    unsigned int m_ticks_till_ripe;
};

#endif
