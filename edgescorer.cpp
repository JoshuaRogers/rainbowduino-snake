#include "edgescorer.h"

#define LIKES_WEIGHT 50
#define DISLIKES_WEIGHT -50

double EdgeScorer::weigh(Coordinate coordinate) {
  int component_edge_count = 0;
  if (is_edge(coordinate.z)) { component_edge_count++; }
  if (is_edge(coordinate.x)) { component_edge_count++; }
  if (is_edge(coordinate.y)) { component_edge_count++; }

  // In a cube, if two of the components are on the edge, it is either an edge or corner.
  return component_edge_count >= 2 ? LIKES_WEIGHT : DISLIKES_WEIGHT;
}

bool EdgeScorer::is_edge(unsigned char point) {
  return point == 0 || point == 3;
}

