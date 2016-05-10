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

  }
  return nextFrontier;
};

template<class Program>
void vertexUpdateSerial(Graph<Vertex>& phigraph,Program& app){

  for(uphiLong i = 0;i < phigraph.vertexNum;i++){
    //uphiLong curVertex = phigraph.v[i];
    app.update(phigraph,i);

  }

};

template<class Program>
void vertexUpdate(Graph<Vertex>& phigraph,Program& app){

  parallel_for(uphiLong i = 0;i < phigraph.vertexNum;i++){
    app.update(phigraph,i);
  }

};


int parallel_main(int argc, char *argv[]) {
  command cmd(argc, argv, " [-s] <inFile>");
  char *iFile = cmd.getArgument(1);
  printf("%s\n",iFile );
  PhiIO* io = new PhiIO();
  #ifdef CSC
  char *iFile2 = cmd.getArgument(2);
  printf("%s\n",iFile2 );
  Graph<Vertex> graph = io->loadGraphFromFile(iFile2,iFile);
  #else
  Graph<Vertex> graph = io->loadGraphFromFile(iFile);
  #endif


  startTime();
  compute(graph);
  nextTime("Running time");
  graph.delgraph();

}

#endif
