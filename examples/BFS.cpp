#include "phigraph.h"

class BFS:public PhiGraphProgram{

public:

  BFS(Graph<Vertex>& phigraph,uphiLong start){

    phigraph.vertex[start].setVisited();

  }
  void update(Graph<Vertex>& phigraph,VertexSubset* nextFrontier,uphiLong curVertex){

    uphiLong degree = phigraph.vertex[curVertex].getOutDegree();
    //printf("vertex[%ld]:degree=%ld\n",curVertex,degree);
    parallel_for(uphiLong j = 0;j < degree;j++){
      phiLong temp = phigraph.vertex[curVertex].getOutVertexes(j);

      if(!phigraph.vertex[temp].isVisited()){
        //printf("%ld\n", phigraph.v[curVertex].getOutVertexes(j));

        phigraph.vertex[temp].setVisited();

        nextFrontier->add(temp);
      }
      //printf("%ld ",phigraph.v[curVertex].getOutVertexes(j));
    }
  }

  void after_iteration(int iteration,VertexSubset* vertexsubset) {
    printf("itereation[%d]:\n",iteration );
    for(long i = 0;i < vertexsubset->m;i++){
      printf("%ld ", vertexsubset->vertex[i]);
    }
    printf("\n");
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
