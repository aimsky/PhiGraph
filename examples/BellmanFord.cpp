
#include "phigraph/phigraph.h"

class BellmanFord:public PhiGraphProgram{
public:
  phiDouble* distance; //save the shortest distance
  //phiLong iteration;
  phiLong vertexNum;
  BellmanFord(Graph<Vertex> & graph,uphiLong start){
    vertexNum = graph.vertexNum;

    distance = phimalloc(phiDouble,vertexNum);
    parallel_for(uphiLong i = 0;i < vertexNum;i++){
      distance[i] = UINT_T_MAX;
    }
    distance[start] = 0.0;
    //iteration = 0;
  }
  void update(Graph<Vertex>& graph,VertexSubset* nextFrontier,uphiLong curVertex){
    uphiLong num = graph.vertex[curVertex].getOutDegree();
    parallel_for(uphiLong i = 0;i < num;i++){

      phiDouble w = graph.vertex[curVertex].getOutWeight(i);
      phiLong temp = graph.vertex[curVertex].getOutVertexes(i);
      if(writeMin(&distance[temp],distance[curVertex] + w)){
        nextFrontier->add(temp);
      }
      // if((distance[curVertex] + w) < distance[temp] ){
      //   //#pragma omp critical
      //
      //   distance[temp] = distance[curVertex] + w;
      //   //#pragma omp critical
      //   nextFrontier->add(temp);
      // }
    }
  }

  bool before_iteration(int iteration,VertexSubset* vertexsubset) {
    if(iteration >= vertexNum){
      printf("negative weighted cycle\n");
      return false;
    }
    printf("itereation[%d]:\n",iteration );
    for(long i = 0;i < vertexsubset->m;i++){
      printf("%ld ", vertexsubset->vertex[i]);
    }
    printf("\n");
    return true;
  }

};
int parallel_main(int argc, char *argv[]) {
  PhiGraphInit graph_init(argc,argv);
  PhiGraphEngine graph_engine(&graph_init.getGraph());
  BellmanFord bellmanford(graph_init.getGraph(),0);
  phiLong n = graph_init.getGraph().vertexNum;
  VertexSubset* frontier = new VertexSubset(n,0);
  graph_engine.exec_vertex(bellmanford,frontier);

}
