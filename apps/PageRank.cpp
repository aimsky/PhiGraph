#define CSC 1
#include "../src/core.hpp"

class PageRank:public PhiGraphProgram{

public:
  PageRank(Graph<Vertex>& phigraph,double f = 1){
    phiLong n = phigraph.vertexNum;
    prValue = phimalloc(double,n);
    parallel_for(phiLong i = 0;i < n;i++){  //pr value first init
      prValue[i] = 1/n;
    }
    factor = f;
  };
  void update(Graph<Vertex>& phigraph,uphiLong curVertex){
    phiLong inDegree = phigraph.v[curVertex].getInDegree();
  }

private:
  double* prValue;
  double factor;//Damping coefficient
};
void compute(Graph<Vertex>& phigraph) {
  long iteration = 40;
  long iter = 0;
  phiLong vertexNum = phigraph.vertexNum;
  for(phiLong i = 0;i < vertexNum;i++){
    for(phiLong j = 0 ;j < phigraph.v[i].getInDegree();j++){
      printf("%ld ",phigraph.v[i].getInVertexes(j) );
    }
    printf("\n");
  }

  // while(iter != iteration){
  //
  //   iter++;
  // }
}
