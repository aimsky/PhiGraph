#ifndef VERTEX_HPP
#define VERTEX_HPP
#include "utils.hpp"
class Vertex{
public:
  Vertex(uphiLong* invertexes,uphiLong* outvertexes,phiLong indegree,phiLong outdegree);
  uphiLong* getInVertexes () { return inVertexes; }
  uphiLong* getOutVertexes () { return outVertexes; }
  uphiLong getInVertexes(uphiLong j) { return inVertexes[j]; }
  uphiLong getOutVertexes(uphiLong j) { return outVertexes[j]; }
  uphiLong getOutDegree() { return outDegree; }
  uphiLong getInDegree() { return inDegree; }
  void setInVertexes(uphiLong* _i) { inVertexes = _i; }
  void setOutVertexes(uphiLong* _i) { outVertexes = _i; }
  void setOutDegree(uphiLong _i) { outDegree = _i; }
  void setInDegree(uphiLong _i) { inDegree = _i; }

  void setOutWeight(phiDouble* _i){ outWeight = _i;}
  phiDouble getOutWeight(uphiLong j){ return outWeight[j];}

  void setVisited(){
    visited = true;
  }
  bool isVisited(){
    return visited;
  }

private:
  uphiLong* inVertexes;
  uphiLong* outVertexes;
  phiDouble* outWeight;
  phiLong inDegree;
  phiLong outDegree;
  bool visited = false;
};

#endif
