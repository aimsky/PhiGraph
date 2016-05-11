#define WEIGHTED 1
#include "../src/core.hpp"

class BellmanFord:public PhiGraphProgram{
public:
  phiDouble* distance; //save the shortest distance
  BellmanFord(Graph<Vertex> & graph,uphiLong start){
    phiLong vertexNum = graph.vertexNum;

    distance = phimalloc(phiDouble,vertexNum);
    parallel_for(uphiLong i = 0;i < vertexNum;i++){
      distance[i] = UINT_T_MAX;
    }
    distance[start] = 0.0;
  }
  phiLong update(Graph<Vertex>& graph,VertexSubset* nextFrontier,uphiLong curVertex){
    uphiLong num = graph.v[curVertex].getOutDegree();
    parallel_for(uphiLong i = 0;i < num;i++){

      phiDouble w = graph.v[curVertex].getOutWeight(i);
      phiLong temp = graph.v[curVertex].getOutVertexes(i);
      if((distance[curVertex] + w) < distance[temp] ){
        //#pragma omp critical
        distance[temp] = distance[curVertex] + w;
        #pragma omp critical
        nextFrontier->add(temp);
      }
    }

  }

};

void compute(Graph<Vertex>& phigraph) {
  uphiLong start = 0;
  phiLong n = phigraph.vertexNum;
  VertexSubset* frontier = new VertexSubset(phigraph.vertexNum,start); //creates initial frontier
  BellmanFord bellmanford(phigraph,start);

  phiLong count = 1;

  while(!frontier->isEmpty()){ //loop until frontier is empty
    count++;
    VertexSubset* output = vertexUpdate(phigraph, frontier, bellmanford);
    //printf("output=%ld\n",output->vertex[0] );
    delete frontier;

    frontier = output; //set new frontier

    if(count > n){
      printf("negative weighted cycle\n");
      break;
    }


  }
  for(phiLong i = 0; i < n;i++){
    printf("%f ",bellmanford.distance[i] );
  }
  delete frontier;

}
