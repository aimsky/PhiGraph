#define CSC 1
#include "../src/core.hpp"

class TopSort:public PhiGraphProgram{
public:
  TopSort(Graph<Vertex>& phigraph){
    phiLong vertexNum = phigraph.vertexNum;
    //sequence = phimalloc(phiLong,vertexNum);
    inDegree = phimalloc(phiLong,vertexNum);
    parallel_for(phiLong i = 0;i < vertexNum;++i){
      inDegree[i] = phigraph.v[i].getInDegree();
    }

  }
  phiLong update(Graph<Vertex>& graph,VertexSubset* nextFrontier,uphiLong curVertex){
    phiLong num = graph.v[curVertex].getOutDegree();
    parallel_for(phiLong i = 0;i < num;++i){
      phiLong id = graph.v[curVertex].getOutVertexes(i);
      #pragma omp atomic
      inDegree[id]--;
      if(inDegree[id] == 0){
        #pragma omp critical
        nextFrontier->add(id);
      }
    }

  }
private:
  //phiLong* sequence;
  phiLong* inDegree;
};

void compute(Graph<Vertex>& phigraph) {
  uphiLong start = 0;
  phiLong n = phigraph.vertexNum;
  VertexSubset* frontier = new VertexSubset(n,start); //creates initial frontier

  TopSort topsort(phigraph);
  while(!frontier->isEmpty()){ //loop until frontier is empty
    VertexSubset* output = vertexUpdate(phigraph, frontier, topsort);
    printf("vertexSubset:" );
    for(long i = 0;i < frontier->m;i++){
      printf("%ld ", frontier->vertex[i]);
    }
    printf("\n");
    delete frontier;
    //printf("frontierdel\n");
    frontier = output; //set new frontier
    //printf("frontierdel2\n");
  }
  delete frontier;

}
