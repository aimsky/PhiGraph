
#include "phigraph_engine.h"


int PhiGraphEngine::MIN_ITERATION_NUM = 4;
PhiGraphEngine::PhiGraphEngine(Graph<Vertex>* graph){
  iteration = 0;
  phigraph = graph;
  machine_core_num = omp_get_num_procs();
  _tm = new Timer();
  //threadNum = dynamicThreadNum(graph->vertexNum);
  //printf("threadNum:t\n", );
  //omp_set_num_threads(threadNum);
  engine_infor(0);
  //kmp_set_defaults
  //kmp_set-defaults("KMP_AFFINITY = scatter");
}
PhiGraphEngine::~PhiGraphEngine(){

}
void PhiGraphEngine::engine_infor(int id){
  if(id == 0){
    printf("PhiGraph Engine is running\n");
    //printf("Thread Num:[%d]\n",threadNum);
  }if(id == 1){
    cout<<"running time:";
    _tm->reportTime(running_time);
  }
}

VertexSubset* PhiGraphEngine::vertexUpdate(Graph<Vertex>& phigraph,VertexSubset* frontier,PhiGraphProgram& app){

  VertexSubset* nextFrontier = new VertexSubset(phigraph.vertexNum);
    //uphiLong temp ;
  //omp_set_nested(true);
  //#pragma omp parallel for num_threads(dynamicThreadNum(frontier->m,MIN_ITERATION_NUM,machine_core_num))
  threadNum = dynamicThreadNum(frontier->m);
  if(threadNum == 1){
    omp_set_num_threads(machine_core_num/2);
    for(uphiLong i = 0;i < frontier->m;i++){

      //printf("ID: %d, Max threads: %d, Num threads: %d \n",omp_get_thread_num(), omp_get_max_threads(), omp_get_num_threads());
      uphiLong curVertex = frontier->vertex[i];
      app.update(phigraph,nextFrontier,curVertex);
      //printf("hahahhhhh\n" );
    }
  }else{
    //printf("frontier:%ld\n",frontier->m );
    omp_set_num_threads(threadNum);
    omp_set_nested(true);
    #pragma omp parallel for schedule(static,4)
    for(uphiLong i = 0;i < frontier->m;i++){

      //printf("ID: %d, Max threads: %d, Num threads: %d \n",omp_get_thread_num(), omp_get_max_threads(), omp_get_num_threads());
      uphiLong curVertex = frontier->vertex[i];
      app.update(phigraph,nextFrontier,curVertex);
      //printf("hahahhhhh\n" );
    }
  }

  return nextFrontier;
};



void PhiGraphEngine::vertexUpdate(Graph<Vertex>& phigraph,PhiGraphProgram& app,bool parallel){
  if(parallel){
    threadNum = dynamicThreadNum(phigraph.vertexNum);
    omp_set_num_threads(threadNum);
    parallel_for(uphiLong i = 0;i < phigraph.vertexNum;i++){
      //if(!app.before_iteration(i))
        //break;
      app.update(phigraph,i);
      //if(!app.after_iteration(i))
      //  break;
    }
  }else{
    for(uphiLong i = 0;i < phigraph.vertexNum;i++){
      if(!app.before_iteration(i))
        break;
      app.update(phigraph,i);
      if(!app.after_iteration(i))
       break;
    }
  }


};


void PhiGraphEngine::exec_vertex(PhiGraphProgram& program,VertexSubset* vertexsubset){

  _tm->start();
  if(vertexsubset != NULL){
    //loop until frontier is empty
    while(!vertexsubset->isEmpty()){
      iteration++;
      //do user difine something before itereation
      if(!program.before_iteration(iteration,vertexsubset))
        break;
      //exute vertex update to vertexSubset
      VertexSubset* output = vertexUpdate(*phigraph, vertexsubset, program);
      //do user difine something after itereation

      delete vertexsubset;
      //set new frontier
      vertexsubset = output;
      if(!program.after_iteration(iteration,vertexsubset))
        break;
    }
  }
  running_time = _tm->next();
  engine_infor(1);
  //PhiGraphEngine::_tm->reportNext("RUNNING TIME:");
  //do user difine something after compution finish
  program.compution_finish();

}
void PhiGraphEngine::exec_vertex(PhiGraphProgram& program,bool parallel,int iteration){
  _tm->start();
  for(int i = 0;i < iteration;i++){
    vertexUpdate(*phigraph,program,parallel);
  }
  running_time = _tm->next();

  //PhiGraphEngine::_tm->reportNext("RUNNING TIME:");
  program.compution_finish();
  engine_infor(1);

}
