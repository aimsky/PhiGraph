#include "phigraph/phigraph.h"
class PageRankVerctor:public PhiGraphProgram{
public:
  double* prValue;
  phiLong vertexNum;
  PageRankVerctor(Graph<Vertex>& phigraph,double f = 1){
    vertexNum = phigraph.vertexNum;
    prValue = phimalloc(double,vertexNum);
    parallel_for(phiLong i = 0;i < vertexNum;i++){  //pr value first init
      prValue[i] = 1;
    }
    factor = f;
  }
  PhiVector<phiDouble>* gather(Graph<Vertex>& phigraph,uphiLong curVertex){
    phiLong inDegree = phigraph.vertex[curVertex].getInDegree();
    PhiVector<phiDouble>* phivector = new PhiVector<phiDouble>(inDegree);
    //printf("%d\n",inDegree );
    parallel_for(phiLong i = 0;i < inDegree;i++){
      phiLong in = phigraph.vertex[curVertex].getInVertexes(i);
      phiDouble value = (prValue[in]/phigraph.vertex[in].getOutDegree());
      phivector->insert(value);
    }

    return phivector;
  }
  void setter(Graph<Vertex>& phigraph,PhiVector<phiDouble>* vec,uphiLong curVertex){
    phiDouble sum = simd_sum(vec);
    //printf("got2\n" );
    phiCAS(&prValue[curVertex],prValue[curVertex],1-factor+ factor*sum);

  }
  void compution_finish() {
    for(int i = 0;i < vertexNum;++i){
      printf("%f ",prValue[i] );
    }
    printf("\n" );
  }
private:
  phiDouble factor;
};

int parallel_main(int argc, char *argv[]) {
  PhiGraphInit graph_init(argc,argv);
  PhiGraphEngine graph_engine(&graph_init.getGraph());
  PageRankVerctor pagerank(graph_init.getGraph(),0.85);
  //phiLong n = graph_init.getGraph().vertexNum;
  //VertexSubset* frontier = new VertexSubset(n,0);
  //for(int i = 0;i < 40;i++){
  graph_engine.exec_gs(pagerank,true,40);

}
