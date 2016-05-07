#include "../src/core.hpp"

class BFS:public PhiGraphProgram{

public:
  //uphiLong* parents;

  BFS(Graph<Vertex>& phigraph,uphiLong start){
    // parents = phimalloc(uphiLong,phigraph.vertexNum);
    // parallel_for(long i=0;i < phigraph.vertexNum;i++) parents[i] = UINT_T_MAX;
    // parents[start] = start;
    phigraph.v[start].setVisited();

  }
  void update(Graph<Vertex>& phigraph,VertexSubset* nextFrontier,uphiLong curVertex){

    uphiLong degree = phigraph.v[curVertex].getOutDegree();
    //printf("vertex[%ld]:degree=%ld\n",curVertex,degree);
    parallel_for(uphiLong j = 0;j < degree;j++){
      phiLong temp = phigraph.v[curVertex].getOutVertexes(j);

      if(!phigraph.v[temp].isVisited()){

        phigraph.v[temp].setVisited();

        nextFrontier->add(temp);
      }
      //printf("%ld ",phigraph.v[curVertex].getOutVertexes(j));
    }
  }
};


class Components:public PhiGraphProgram{
public:
  Components(){
    componentsNum = 0;

  };
  phiLong componentsNum;
  void update(Graph<Vertex>& phigraph,uphiLong curVertex){
    if(!phigraph.v[curVertex].isVisited()){
      comp(phigraph,curVertex);
      #pragma omp atomic
      componentsNum++;
    }
  }
  void comp(Graph<Vertex>& phigraph,uphiLong start) {
    phiLong n = phigraph.vertexNum;
    VertexSubset* frontier = new VertexSubset(n,start); //creates initial frontier
    BFS bfs(phigraph,start);
    while(!frontier->isEmpty()){ //loop until frontier is empty
      VertexSubset* output = vertexUpdate(phigraph, frontier, bfs);
      delete frontier;
      frontier = output; //set new frontier
    }
    delete frontier;
  }
};

void compute(Graph<Vertex>& phigraph) {
  Components components;
  vertexUpdateSerial(phigraph, components);
  printf("%ld\n",components.componentsNum );

}
