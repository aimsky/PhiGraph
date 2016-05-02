#include "../src/core.hpp"

class BFS:public PhiGraphProgram{


public:
  uphiLong* parents;

  BFS(Graph<Vertex>& phigraph,uphiLong start){
    parents = phimalloc(uphiLong,phigraph.vertexNum);
    parallel_for(long i=0;i < phigraph.vertexNum;i++) parents[i] = UINT_T_MAX;
    parents[start] = start;



  }
  bool update(uphiLong s,uphiLong d){
    if(parents[d] == UINT_T_MAX) { parents[d] = s; return 1; }
    else {
    // printf("false\n");
    // printf("d=%ld,parents=%ld\n",d,parents[d] );
      return 0;
    }
  }
};

void compute(Graph<Vertex>& phigraph) {
  uphiLong start = 0;
  phiLong n = phigraph.vertexNum;
  VertexSubset* frontier = new VertexSubset(n,start); //creates initial frontier

  BFS bfs(phigraph,start);
  while(!frontier->isEmpty()){ //loop until frontier is empty
    VertexSubset* output = edgeUpdate(phigraph, frontier, bfs);
    printf("vertexSubset:" );
    for(long i = 0;i < output->m;i++){
      printf("%ld ", output->vertex[i]);
    }
    printf("\n");
    delete frontier;
    //printf("frontierdel\n");
    frontier = output; //set new frontier
    //printf("frontierdel2\n");
  }
  delete frontier;
  //free(parents);
  // for (phiLong i=0; i < phigraph.vertexNum; i++) {
  //   uphiLong degree = phigraph.v[i].getOutDegree();
  //   printf("vertex[%ld]:degree=%ld\n",i,degree);
  //   for(unsigned long j = 0;j<degree;j++){
  //     printf("%ld ",phigraph.v[i].getOutVertexes(j));
  //   }
  //   printf("\n");
  // }
}
