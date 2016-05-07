#define WEIGHTED 1
#include "../src/core.hpp"

class SSSP:public PhiGraphProgram{

public:
  uphiLong* visit;
  phiDouble* distance; //save the shortest distance

  SSSP(phiLong vertexNum,uphiLong start,Graph<Vertex> & graph){ //sssp initial
    visit = phimalloc(uphiLong,vertexNum);
    parallel_for(long i=0;i < vertexNum;i++) visit[i] = 0;
    visit[start] = 1;

    distance = phimalloc(phiDouble,vertexNum);
    parallel_for(uphiLong i = 0;i < vertexNum;i++){
      distance[i] = UINT_T_MAX;
    }
    parallel_for(uphiLong i = 0;i < graph.v[start].getOutDegree();i++){
      distance[graph.v[start].getOutVertexes(i)] = graph.v[start].getOutWeight(i);
    }
    distance[start] = 0.0;

  }
  phiLong update(Graph<Vertex>& graph,VertexSubset* nextFrontier,uphiLong curVertex){
    uphiLong num = graph.vertexNum;
    uphiLong min = UINT_T_MAX;
    uphiLong nextVertexId = -1;

    parallel_for(uphiLong i = 0;i < num;i++){
      #pragma omp critical
      if(!visit[i] && distance[i] < min){
        nextVertexId = i;
        min = distance[i];
      }
    }

    if(nextVertexId != -1)
      visit[nextVertexId] = 1;
    else
      return UINT_T_MAX;

    parallel_for(uphiLong i = 0;i < graph.v[nextVertexId].getOutDegree();i++){
      #pragma omp critical
      if(!visit[graph.v[nextVertexId].getOutVertexes(i)] &&  (min + graph.v[nextVertexId].getOutWeight(i)) < distance[graph.v[nextVertexId].getOutVertexes(i)]){
        distance[graph.v[nextVertexId].getOutVertexes(i)] = min + graph.v[nextVertexId].getOutWeight(i);
      }
    }

    //printf("nextId:%ld\n", nextVertexId);
    nextFrontier->add(nextVertexId);
  }
};

void compute(Graph<Vertex>& phigraph) {
  uphiLong start = 0;
  phiLong n = phigraph.vertexNum;
  VertexSubset* frontier = new VertexSubset(phigraph.vertexNum,start); //creates initial frontier
  SSSP sssp(n,start,phigraph);
  while(!frontier->isEmpty()){ //loop until frontier is empty
    VertexSubset* output = vertexUpdate(phigraph, frontier, sssp);
    //printf("output=%ld\n",output->vertex[0] );
    delete frontier;

    frontier = output; //set new frontier

  }
  // for(long i = 0;i < n;i++){
  //   VertexSubset* output = vertexUpdate(phigraph, frontier, sssp);
  //   delete frontier;
  //   frontier = output; //set new frontier
  // }
  delete frontier;

}
