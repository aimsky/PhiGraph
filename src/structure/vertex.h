#ifndef VERTEX_HPP
#define VERTEX_HPP
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"

class Vertex{
public:
  Vertex();
  Vertex(uphiLong* invertexes,uphiLong* outvertexes,phiLong indegree,phiLong outdegree);
  uphiLong* getInVertexes ();
  uphiLong* getOutVertexes ();
  uphiLong getInVertexes(uphiLong j);
  uphiLong getOutVertexes(uphiLong j);
  uphiLong getOutDegree();
  uphiLong getInDegree();
  void setInVertexes(uphiLong* _i);
  void setOutVertexes(uphiLong* _i);
  void setOutDegree(uphiLong _i);
  void setInDegree(phiLong _i);
  void setOutWeight(phiDouble* _i);
  void setInWeight(phiDouble* _i);
  phiDouble getOutWeight(uphiLong j);
  phiDouble getInWeight(uphiLong j);
  void setVisited();
  bool isVisited();
  ~Vertex();

private:
  uphiLong* inVertexes;
  uphiLong* outVertexes;
  phiDouble* outWeight;
  phiDouble* inWeight;
  phiLong inDegree;
  phiLong outDegree;
  bool visited;
};

#endif
