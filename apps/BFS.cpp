#include "../src/core.hpp"

class BFS:public PhiGraphProgram{

public:
  uphiLong* parents;

  BFS(Graph<Vertex>& phigraph,uphiLong start){
    ///parents = phimalloc(uphiLong,phigraph.vertexNum);
    //parallel_for(long i=0;i < phigraph.vertexNum;i++) parents[i] = UINT_T_MAX;
    //parents[start] = start;
    phigraph.v[start].setVisited();

  }
  void update(Graph<Vertex>& phigraph,VertexSubset* nextFrontier,uphiLong curVertex){

    uphiLong degree = phigraph.v[curVertex].getOutDegree();
    //printf("vertex[%ld]:degree=%ld\n",curVertex,degree);
    parallel_for(uphiLong j = 0;j < degree;j++){
      phiLong temp = phigraph.v[curVertex].getOutVertexes(j);
      //#pragma omp critical
      if(!phigraph.v[temp].isVisited()){
        //printf("%ld\n", phigraph.v[curVertex].getOutVertexes(j));

        phigraph.v[temp].setVisited();

        nextFrontier->add(temp);
      }
      //printf("%ld ",phigraph.v[curVertex].getOutVertexes(j));
    }
  }
};

void compute(Graph<Vertex>& phigraph) {
  uphiLong start = 0;
  phiLong n = phigraph.vertexNum;
  VertexSubset* frontier = new VertexSubset(n,start); //creates initial frontier

  BFS bfs(phigraph,start);
  while(!frontier->isEmpty()){ //loop until frontier is empty
    VertexSubset* output = vertexUpdate(phigraph, frontier, bfs);
    // printf("vertexSubset:" );
    // for(long i = 0;i < frontier->m;i++){
    //   printf("%ld ", frontier->vertex[i]);
    // }
    // printf("\n");
    delete frontier;
    //printf("frontierdel\n");
    frontier = output; //set new frontier
    //printf("frontierdel2\n");
  }
  delete frontier;

}
