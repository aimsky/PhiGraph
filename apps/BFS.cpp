#include "../src/core.hpp"

void Compute(Graph<Vertex> phigraph) {
  parallel_for (phiLong i=0; i < phigraph.vertexNum; i++) {
    uphiLong degree = phigraph.v[i].getOutDegree();
    printf("vertex[%ld]:degree=%ld\n",i,degree);
    for(unsigned long j = 0;j<degree;j++){
      printf("%ld ",phigraph.v[i].getOutVertexes(j));
    }
    printf("\n");
  }
}
