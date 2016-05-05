#ifndef VERTEX_HPP
#define VERTEX_HPP
#include "utils.hpp"
#include <stdio.h>
#include <stdlib.h>
class Vertex{
public:
  Vertex(){
    //inVertexes = NULL;
    //outVertexes = NULL;
    visited = false;
  }
  Vertex(uphiLong* invertexes,uphiLong* outvertexes,phiLong indegree,phiLong outdegree){
    inVertexes = invertexes;
    outVertexes = outvertexes;
    inDegree = indegree;
    outDegree = outdegree;
    visited = false;
  };
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
  void setInWeight(phiDouble* _i){ inWeight = _i;}
  phiDouble getOutWeight(uphiLong j){ return outWeight[j];}
  phiDouble getInWeight(uphiLong j){ return inWeight[j];}

  void setVisited(){
    visited = true;
  }
  bool isVisited(){
    return visited;
  }
  ~Vertex(){
    // if(NULL != inVertexes)
    //   free(inVertexes);
    // if(NULL != outVertexes)
    //   free(outVertexes);
    #ifdef WEIGHTED
    //free(outWeight);
    #endif
    //printf("delete\n");
  }

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
