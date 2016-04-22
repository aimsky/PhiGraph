#ifndef VERTEX_HPP
#define VERTEX_HPP
#include "utils.hpp"
class Vertex{
public:
  Vertex(uPhiLong* invertexes,uPhiLong* outvertexes,PhiLong indegree,PhiLong outdegree);
  uPhiLong* getInVertexes () { return inVertexes; }
  uPhiLong* getoutVertexes () { return outVertexes; }
  uPhiLong getInVertexes(uPhiLong j) { return inVertexes[j]; }
  uPhiLong getOutVertexes(uPhiLong j) { return outVertexes[j]; }
  void setinVertexes(uPhiLong* _i) { inVertexes = _i; }
  void setoutVertexes(uPhiLong* _i) { outVertexes = _i; }
private:
  uPhiLong* inVertexes;
  uPhiLong* outVertexes;
  PhiLong inDegree;
  PhiLong outDegree;
};


#endif
