#ifndef GRAPH_H
#define GRAPH_H

template <class vertex>
class Graph{
public:
  vertex *v;
  long n;
  long m;
  unsigned long flags;
  Graph(vertex* vt,long nt,long mt): v(vt),n(nt),m(mt){};
  void delgraph(){
    free(v);
  }
};

#endif
