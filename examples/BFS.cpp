#include "phigraph/phigraph.h"

class BFS:public PhiGraphProgram{

public:
  uphiLong* parents;
  BFS(Graph<Vertex>& phigraph,uphiLong start){

    //phigraph.vertex[start].setVisited();
    parents = phimalloc(uphiLong,phigraph.vertexNum);
    parallel_for(phiLong i = 0;i < phigraph.vertexNum;++i){
      parents[i] = -1;
    }
    parents[start] = start;

  }
  void update(Graph<Vertex>& phigraph,VertexSubset* nextFrontier,uphiLong curVertex){

    uphiLong degree = phigraph.vertex[curVertex].getOutDegree();
    //int threadNum = dynamicThreadNum(degree);
    //printf("threadNum:t\n", );
    //omp_set_num_threads(threadNum);
    //printf("vertex[%ld]:degree=%ld\n",curVertex,degree);
    for(uphiLong j = 0;j < degree;j++){
      phiLong temp = phigraph.vertex[curVertex].getOutVertexes(j);

      if(phiCAS(&parents[temp],(uphiLong)-1,curVertex)){
        //printf("%ld\n", phigraph.v[curVertex].getOutVertexes(j));

        //phigraph.vertex[temp].setVisited();

        nextFrontier->add(temp);
      }
      //printf("%ld ",phigraph.v[curVertex].getOutVertexes(j));
    }
  }

  bool after_iteration(int iteration,VertexSubset* vertexsubset) {
    // printf("itereation[%d]:\n",iteration );
    // for(long i = 0;i < vertexsubset->m;i++){
    //   printf("%ld ", vertexsubset->vertex[i]);
    // }
    // printf("\n");
    return true;
  }

};
int parallel_main(int argc, char *argv[]) {
  PhiGraphInit graph_init(argc,argv);
  PhiGraphEngine graph_engine(&graph_init.getGraph());
  BFS bfs(graph_init.getGraph(),0);
  phiLong n = graph_init.getGraph().vertexNum;
  VertexSubset* frontier = new VertexSubset(n,0);
  graph_engine.exec_vertex(bfs,frontier);

}
