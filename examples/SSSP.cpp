#include "phigraph.h"
class SSSP:public PhiGraphProgram{

  public:
    uphiLong* visit;
    phiDouble* distance; //save the shortest distance
    phiLong vertexNum;
    phiDouble min;
    uphiLong nextVertexId;
    SSSP(Graph<Vertex> & graph,uphiLong start){ //sssp initial
      vertexNum = graph.vertexNum;
      visit = phimalloc(uphiLong,vertexNum);
      parallel_for(long i=0;i < vertexNum;i++)
        visit[i] = 0;

      visit[start] = 1;

      distance = phimalloc(phiDouble,vertexNum);
      parallel_for(uphiLong i = 0;i < vertexNum;i++){
        distance[i] = UINT_T_MAX;
      }
      parallel_for(uphiLong i = 0;i < graph.vertex[start].getOutDegree();i++){
        distance[graph.vertex[start].getOutVertexes(i)] = graph.vertex[start].getOutWeight(i);
      }
      distance[start] = 0.0;

      min = UINT_T_MAX;
      nextVertexId = -1;

    }
    void update(Graph<Vertex>& graph,VertexSubset* nextFrontier,uphiLong curVertex){

      min = UINT_T_MAX;
      nextVertexId = -1;
      parallel_for(uphiLong i = 0;i < vertexNum;i++){
        //#pragma omp critical
        if(!visit[i]){

          if(writeMin(&min,distance[i]))
            phiCAS(&nextVertexId,nextVertexId,i);

        }
      }

      if(nextVertexId != -1){
        visit[nextVertexId] = 1;
        parallel_for(uphiLong i = 0;i < graph.vertex[nextVertexId].getOutDegree();i++){
          //#pragma omp critical
          phiDouble temp = distance[graph.vertex[nextVertexId].getOutVertexes(i)];
          if(!visit[graph.vertex[nextVertexId].getOutVertexes(i)] &&  (min + graph.vertex[nextVertexId].getOutWeight(i)) < temp){
            //distance[graph.vertex[nextVertexId].getOutVertexes(i)] = min + graph.vertex[nextVertexId].getOutWeight(i);
            //__sync_fetch_and_add(distance[graph.vertex[nextVertexId].getOutVertexes(i)], min);
            //printf("good haha\n" );
            phiCAS(&distance[graph.vertex[nextVertexId].getOutVertexes(i)],temp,graph.vertex[nextVertexId].getOutWeight(i)+min);
          }
        }

        printf("nextId:%ld\n", nextVertexId);
        nextFrontier->add(nextVertexId);
      }else return;

    }

};
int parallel_main(int argc, char *argv[]) {
  PhiGraphInit graph_init(argc,argv);
  PhiGraphEngine graph_engine(&graph_init.getGraph());
  SSSP sssp(graph_init.getGraph(),0);
  phiLong n = graph_init.getGraph().vertexNum;
  VertexSubset* frontier = new VertexSubset(n,0);
  graph_engine.exec_vertex(sssp,frontier);

}
