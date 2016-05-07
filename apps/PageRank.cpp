#define CSC 1
#include "../src/core.hpp"

class PageRank:public PhiGraphProgram{

public:
  double* prValue;
  PageRank(Graph<Vertex>& phigraph,double f = 1){
    phiLong n = phigraph.vertexNum;
    prValue = phimalloc(double,n);
    parallel_for(phiLong i = 0;i < n;i++){  //pr value first init
      prValue[i] = 1;
    }
    factor = f;
  };
  void update(Graph<Vertex>& phigraph,uphiLong curVertex){
    phiLong inDegree = phigraph.v[curVertex].getInDegree();
    phiDouble sum = 0.0;
    parallel_for(phiLong i = 0;i < inDegree;i++){
      phiLong in = phigraph.v[curVertex].getInVertexes(i);
      #pragma omp atomic
      sum += (prValue[in]/phigraph.v[in].getOutDegree());
    }
    prValue[curVertex] = 1-factor+ factor*sum;
  }

private:

  double factor;//Damping coefficient
};
void compute(Graph<Vertex>& phigraph) {
  long iteration = 40;
  long iter = 0;
  PageRank pagerank(phigraph,0.85);
  phiLong vertexNum = phigraph.vertexNum;
  for(phiLong i = 0;i < vertexNum;i++){
    for(phiLong j = 0 ;j < phigraph.v[i].getInDegree();j++){
      printf("%ld ",phigraph.v[i].getInVertexes(j) );
    }
    printf("\n");
  }
  for(long i = 0;i < iteration;i++){
    vertexUpdate(phigraph, pagerank);

  }
  for(long i = 0;i < phigraph.vertexNum;i++){
    printf("%f ",pagerank.prValue[i] );
  }

  // while(iter != iteration){
  //
  //   iter++;
  // }
}
