#include "phigraph/phigraph.h"

class TopSort:public PhiGraphProgram{
public:
  phiLong start;
  TopSort(Graph<Vertex>& phigraph){
    phiLong vertexNum = phigraph.vertexNum;
    phiLong flag = 0;
    //sequence = phimalloc(phiLong,vertexNum);
    inDegree = phimalloc(phiLong,vertexNum);
    parallel_for(phiLong i = 0;i < vertexNum;++i){
      inDegree[i] = phigraph.vertex[i].getInDegree();
      if(!flag && inDegree[i] == 0){
        flag = 1;
        start = i;
      }
    }
    printf("start=\n",start );

  }
  void update(Graph<Vertex>& graph,VertexSubset* nextFrontier,uphiLong curVertex){
    phiLong num = graph.vertex[curVertex].getOutDegree();
    parallel_for(phiLong i = 0;i < num;++i){
      phiLong id = graph.vertex[curVertex].getOutVertexes(i);
      // #pragma omp atomic
      // inDegree[id]--;
      writeAdd(&inDegree[id],(phiLong)-1);
      if(inDegree[id] == 0){
        //#pragma omp critical
        nextFrontier->add(id);
      }
    }

  }
  bool after_iteration(int iteration,VertexSubset* vertexsubset) {
    printf("itereation[%d]:\n",iteration );
    for(long i = 0;i < vertexsubset->m;i++){
      printf("%ld ", vertexsubset->vertex[i]);
    }
    printf("\n");
    return true;
  }
private:
  //phiLong* sequence;
  phiLong* inDegree;
};

int parallel_main(int argc, char *argv[]) {
  PhiGraphInit graph_init(argc,argv);
  PhiGraphEngine graph_engine(&graph_init.getGraph());
  TopSort topsort(graph_init.getGraph());
  phiLong n = graph_init.getGraph().vertexNum;
  VertexSubset* frontier = new VertexSubset(n,topsort.start);
  graph_engine.exec_vertex(topsort,frontier);

}
