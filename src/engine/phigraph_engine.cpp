
#include "phigraph_engine.h"

Timer* PhiGraphEngine::_tm = new Timer();
int PhiGraphEngine::MIN_ITERATION_NUM = 4;
PhiGraphEngine::PhiGraphEngine(Graph<Vertex>* graph){
  iteration = 0;
  phigraph = graph;
  machine_core_num = omp_get_num_procs();
}
PhiGraphEngine::~PhiGraphEngine(){

}

VertexSubset* PhiGraphEngine::vertexUpdate(Graph<Vertex>& phigraph,VertexSubset* frontier,PhiGraphProgram& app){

  VertexSubset* nextFrontier = new VertexSubset(phigraph.vertexNum);
    //uphiLong temp ;
  //omp_set_nested(true);
  //#pragma omp parallel for num_threads(dynamicThreadNum(frontier->m,MIN_ITERATION_NUM,machine_core_num))
  for(uphiLong i = 0;i < frontier->m;i++){
    //printf("ID: %d, Max threads: %d, Num threads: %d \n",omp_get_thread_num(), omp_get_max_threads(), omp_get_num_threads());
    uphiLong curVertex = frontier->vertex[i];
    app.update(phigraph,nextFrontier,curVertex);
    //printf("hahahhhhh\n" );
  }
  return nextFrontier;
};



void PhiGraphEngine::vertexUpdate(Graph<Vertex>& phigraph,PhiGraphProgram& app){

  for(uphiLong i = 0;i < phigraph.vertexNum;i++){
    if(!app.before_iteration(i))
      break;
    app.update(phigraph,i);
    if(!app.after_iteration(i))
      break;
  }

};


void PhiGraphEngine::exec_vertex(PhiGraphProgram& program,VertexSubset* vertexsubset){

  PhiGraphEngine::_tm->start();
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
  PhiGraphEngine::_tm->reportNext("RUNNING TIME:");
  //do user difine something after compution finish
  program.compution_finish();
}
void PhiGraphEngine::exec_vertex(PhiGraphProgram& program,int iteration){
  PhiGraphEngine::_tm->start();
  for(int i = 0;i < iteration;i++){
    vertexUpdate(*phigraph,program);
  }
  PhiGraphEngine::_tm->reportNext("RUNNING TIME:");
  program.compution_finish();
}
