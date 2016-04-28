#include "../src/core.hpp"

class BFS:public PhiGraphProgram{
public:
  uphiLong* parents;
  BFS(phiLong n,uphiLong start){
    parents = phimalloc(uphiLong,n);
    parallel_for(long i=0;i<n;i++) parents[i] = UINT_T_MAX;
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

  VertexSubset frontier(n,start); //creates initial frontier
  BFS bfs(n,start);
  // while(!Frontier.isEmpty()){ //loop until frontier is empty
  vertexUpdate(phigraph, frontier, bfs);
  //   frontier.del();
  //   frontier = output; //set new frontier
  // }
  frontier.del();
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
