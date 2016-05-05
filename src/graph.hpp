#ifndef GRAPH_H
#define GRAPH_H
#include "utils.hpp"
template <class vertex>
class Graph{
public:
  vertex *v;
  phiLong vertexNum;
  phiLong edgeNum;
  unsigned long flags;
  Graph(vertex* vt,phiLong nt,phiLong mt): v(vt),vertexNum(nt),edgeNum(mt){};
  void delgraph(){
    //free(v);
    delete [] v;
  }
};

#endif
