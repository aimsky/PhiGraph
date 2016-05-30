#ifndef GRAPH_H
#define GRAPH_H
#include "../utils/utils.h"
template <class Vertex>
class Graph{
public:
  Vertex *vertex;
  phiLong vertexNum;
  phiLong edgeNum;
  unsigned long flags;
  Graph(Vertex* vt,phiLong nt,phiLong mt): vertex(vt),vertexNum(nt),edgeNum(mt){};
  void delgraph(){
    //free(v);
    delete [] vertex;
  }
};

#endif
