#include "phigraph.h"

class PageRank:public PhiGraphProgram{

public:
  double* prValue;
  phiLong num;
  PageRank(Graph<Vertex>& phigraph,double f = 1){
    num = phigraph.vertexNum;
    prValue = phimalloc(double,num);
    parallel_for(phiLong i = 0;i < num;i++){  //pr value first init
      prValue[i] = 1;
    }
    factor = f;
  };

  void update(Graph<Vertex>& phigraph,uphiLong curVertex){
    phiLong inDegree = phigraph.vertex[curVertex].getInDegree();
    phiDouble sum = 0.0;
    simd_for(phiLong i = 0;i < inDegree;i++){
      phiLong in = phigraph.vertex[curVertex].getInVertexes(i);
      phiDouble value = (prValue[in]/phigraph.vertex[in].getOutDegree());
      writeAdd(&sum,value);
      //#pragma omp atomic
      //sum +=
    }
    phiCAS(&prValue[curVertex],prValue[curVertex],1-factor+ factor*sum);
    //prValue[curVertex] = 1-factor+ factor*sum;
  }
  void compution_finish() {
    for(int i = 0;i < num;++i){
      printf("%f ",prValue[i] );
    }
    printf("\n" );
  }

private:


  double factor;//Damping coefficient
};
int parallel_main(int argc, char *argv[]) {
  PhiGraphInit graph_init(argc,argv);
  PhiGraphEngine graph_engine(&graph_init.getGraph());
  PageRank pagerank(graph_init.getGraph(),0.85);
  //phiLong n = graph_init.getGraph().vertexNum;
  //VertexSubset* frontier = new VertexSubset(n,0);
  //for(int i = 0;i < 40;i++){
  graph_engine.exec_vertex(pagerank,40);
  //}



}
