
#include "phigraph.h"

class BFS:public PhiGraphProgram{

public:
  phiLong* path_num;
  phiLong* delta;
  phiLong vertexNum;
  BFS(Graph<Vertex>& phigraph,uphiLong start,phiLong* path,phiLong* d){
    vertexNum = phigraph.vertexNum;
    path_num = path;
    delta = d;

    parallel_for(phiLong i = 0;i < vertexNum;i++){
      path_num[i] = -1;
    }

    parallel_for(phiLong i = 0;i < vertexNum;i++){
      delta[i] = 0;
    }
    path_num[start] = 0;
    delta[start] = 1;
  }
  void update(Graph<Vertex>& phigraph,VertexSubset* nextFrontier,uphiLong curVertex){


    uphiLong degree = phigraph.vertex[curVertex].getOutDegree();
    //printf("vertex[%ld]:degree=%ld\n",curVertex,degree);
    parallel_for(uphiLong j = 0;j < degree;j++){
      phiLong out = phigraph.vertex[curVertex].getOutVertexes(j);
      //#pragma omp atomic
      //path_num[temp]++;
      if(path_num[out] == -1){
        phiCAS(&path_num[out],path_num[out],path_num[curVertex]+1);
        //writeAdd(&path_num[out],path_num[curVertex]);
        nextFrontier->add(out);
      }

      if(path_num[out] == (path_num[curVertex]+1))
        writeAdd(&delta[out],delta[curVertex]);

    }

  }

};


class BC:public PhiGraphProgram{

public:
  phiLong* path_num;
  phiLong vertexNum;
  //BFS* bfs;
  phiDouble* dependency;
  phiLong* delta;
  PhiGraphEngine* engine;
  VertexSubset** level;
  phiDouble* centric;
  phiLong* visit;
  BC(Graph<Vertex>& phigraph,uphiLong start){
    vertexNum = phigraph.vertexNum;
    path_num = phimalloc(phiLong,vertexNum);

    //path_num = phimalloc(phiLong,vertexNum);
    //parallel_for(phiLong i = 0;i < 5;i++){
    level = phimalloc(VertexSubset*,vertexNum);
    //}

    centric = phimalloc(phiDouble,vertexNum);
    parallel_for(phiLong i = 0;i < vertexNum;i++){
      centric[i] = 0;
    }

    delta = phimalloc(phiLong,vertexNum);

    //path_num[start] = 1;
    dependency = phimalloc(phiDouble,vertexNum);
    visit = phimalloc(phiLong,vertexNum);

    //phigraph.vertex[start].setVisited();
    engine = new PhiGraphEngine(&phigraph);
    //bfs = new BFS(phigraph,start,path_num,delta);
  }

  void compution_finish(){
    printf("result:\n" );
    for(long i = 0;i < vertexNum;i++){
      printf("%f ", centric[i]);
    }
    printf("\n");
    //return true;
  }
  bool after_iteration(int iteration) {

    //printf("itereation[%d]:\n",iteration );
    // for(long i = 0;i < vertexNum;i++){
    //   printf("%f ", dependency[i]);
    // }
    // printf("\n");
    return true;
  }

  void update(Graph<Vertex>& phigraph,uphiLong curVertex){
    parallel_for(phiLong i = 0;i < vertexNum;i++){
      dependency[i] = 0.0;
    }
    parallel_for(phiLong i = 0;i < vertexNum;i++){
      visit[i] = 0;
    }
    visit[curVertex] = 1;

    VertexSubset* frontier = new VertexSubset(vertexNum,curVertex); //creates initial frontier
    phiLong it = 0;
    BFS* bfs = new BFS(phigraph,curVertex,path_num,delta);
    while(!frontier->isEmpty()){ //loop until frontier is empty
      frontier = engine->vertexUpdate(phigraph, frontier, *bfs);
      level[it] = frontier;
      it++;
    }
    // for(int i=0;i<vertexNum;i++){
    //   printf("%ld ",path_num[i] );
    // }
    // printf("\n" );
    // for(int i=0;i<vertexNum;i++){
    //   printf("%ld ",delta[i] );
    // }
    // printf("\n" );
    for(phiLong i = it-1;i >=0;i--){
      parallel_for(uphiLong j = 0;j < level[i]->m;j++){
        //printf("ID: %d, Max threads: %d, Num threads: %d \n",omp_get_thread_num(), omp_get_max_threads(), omp_get_num_threads());
        uphiLong curVertex = level[i]->vertex[j];
        visit[curVertex] = 1;
        //printf("curVertex:%d\n",curVertex );
        for(phiLong x = 0;x < phigraph.vertex[curVertex].getInDegree();x++){
          phiLong In = phigraph.vertex[curVertex].getInVertexes(x);
          if(visit[In] == 0){
            phiDouble temp = ((phiDouble)delta[In]/(phiDouble)delta[curVertex])*(1 + dependency[curVertex]);
            writeAdd(&dependency[In],temp);
          }
        }
      }
      delete level[i];
    }

    parallel_for(phiLong i = 0;i < vertexNum;i++){
      visit[i] = 0;
      writeAdd(&centric[i],dependency[i]);
    }
    delete bfs;
    // if(curVertex != start){
    //    centric[curVertex] = centric[curVertex]+dependency[curVertex];
    // }
  }

};
int parallel_main(int argc, char *argv[]) {
  PhiGraphInit graph_init(argc,argv);
  PhiGraphEngine graph_engine(&graph_init.getGraph());
  BC bc(graph_init.getGraph(),0);
  phiLong n = graph_init.getGraph().vertexNum;
  //VertexSubset* frontier = new VertexSubset(n,0);
  graph_engine.exec_vertex(bc,false);

}
