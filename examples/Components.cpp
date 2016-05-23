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

};
class Components:public PhiGraphProgram{
public:
  phiLong componentsNum;
  PhiGraphEngine* bfs_engine;
  phiLong vertexNum;
  Components(Graph<Vertex>& phigraph){
    componentsNum = 0;
    bfs_engine = new PhiGraphEngine(&phigraph);
    vertexNum = phigraph.vertexNum;
  };

  void update(Graph<Vertex>& phigraph,uphiLong curVertex){
    if(!phigraph.vertex[curVertex].isVisited()){
      BFS bfs(phigraph,curVertex);
      VertexSubset* frontier = new VertexSubset(vertexNum,curVertex);
      bfs_engine->exec_vertex(bfs,frontier);
      //comp(phigraph,curVertex);
      //#pragma omp atomic
      componentsNum++;
    }
  }
  void compution_finish() {
    printf("components:%ld\n",componentsNum );
  }

};
int parallel_main(int argc, char *argv[]) {
  PhiGraphInit graph_init(argc,argv);
  PhiGraphEngine graph_engine(&graph_init.getGraph());
  Components components(graph_init.getGraph());
  phiLong n = graph_init.getGraph().vertexNum;
  //VertexSubset* frontier = new VertexSubset(n,0);
  graph_engine.exec_vertex(components);

}
