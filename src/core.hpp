#ifndef CORE_HPP
#define CORE_HPP

#include "IO.hpp"
#include "command.hpp"
#include "vertexSubset.hpp"
#include "gettime.h"
#include <stdio.h>
using namespace phigraph;

void compute(Graph<Vertex>& phigraph);
void gather(VertexSubset* vs);
VertexSubset setter(phiLong* data);

class PhiGraphProgram{
public:
  PhiGraphProgram(){};
  virtual bool condition(){};
  virtual phiLong update(){};
  virtual void gather(){};
  virtual void setter(){};

};
template<class Program>
VertexSubset* vertexUpdate(Graph<Vertex>& phigraph,VertexSubset* frontier,Program& app){

  VertexSubset* nextFrontier = new VertexSubset(phigraph.vertexNum);
  //uphiLong temp ;
  parallel_for(uphiLong i = 0;i < frontier->m;i++){
    uphiLong curVertex = frontier->vertex[i];
    app.update(phigraph,nextFrontier,curVertex);
    // temp = app.update(phigraph,curVertex);
    // #pragma omp critical
    // if(temp != UINT_T_MAX){
    //   nextFrontier->add(temp);
    // }
  }
  return nextFrontier;
};

template<class Program>
VertexSubset* edgeUpdate(Graph<Vertex>& phigraph,VertexSubset* frontier,Program& app){

  VertexSubset* nextFrontier = new VertexSubset(phigraph.vertexNum);
  parallel_for(uphiLong i = 0;i < frontier->m;i++){
    uphiLong curVertex = frontier->vertex[i];
    app.update(phigraph,nextFrontier,curVertex);
    // uphiLong degree = phigraph.v[curVertex].getOutDegree();
    // //printf("vertex[%ld]:degree=%ld\n",curVertex,degree);
    // parallel_for(uphiLong j = 0;j < degree;j++){
    //   #pragma omp critical
    //   if(app.update(curVertex,phigraph.v[curVertex].getOutVertexes(j))){
    //     //printf("%ld\n", phigraph.v[curVertex].getOutVertexes(j));
    //     nextFrontier->add(phigraph.v[curVertex].getOutVertexes(j));
    //   }
    //   //printf("%ld ",phigraph.v[curVertex].getOutVertexes(j));
    // }
  }
  return nextFrontier;
};


int parallel_main(int argc, char *argv[]) {
  command cmd(argc, argv, " [-s] <inFile>");
  char *iFile = cmd.getArgument(0);
  PhiIO* io = new PhiIO();
  Graph<Vertex> graph = io->loadGraphFromFile(iFile);

  startTime();
  compute(graph);
  nextTime("Running time");
  graph.delgraph();

}

#endif
