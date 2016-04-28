#ifndef CORE_HPP
#define CORE_HPP

#include "IO.hpp"
#include "command.hpp"
#include "vertexSubset.hpp"
#include <stdio.h>
using namespace phigraph;

void compute(Graph<Vertex>& phigraph);
void gather(VertexSubset* vs);
VertexSubset setter(phiLong* data);

class PhiGraphProgram{
public:
  PhiGraphProgram(){};
  virtual bool condition(){};
  virtual bool update(){};
};
template<class Program>
void vertexUpdate(Graph<Vertex>& phigraph,VertexSubset& frontier,Program& app){
  //printf("vertexUpdate\n");
  //phiLong* nextIndices = phi
  parallel_for(uphiLong i = 0;i < frontier.m;i++){
    uphiLong curVertex = frontier.s[i];
    uphiLong degree = phigraph.v[curVertex].getOutDegree();
    //printf("vertex[%ld]:degree=%ld\n",curVertex,degree);
    parallel_for(uphiLong j = 0;j < degree;j++){
      if(app.update(curVertex,phigraph.v[curVertex].getOutVertexes(j)))
        printf("%ld\n", phigraph.v[curVertex].getOutVertexes(j));
      //printf("%ld ",phigraph.v[curVertex].getOutVertexes(j));
    }
  }
};

int parallel_main(int argc, char *argv[]) {
  command cmd(argc, argv, " [-s] <inFile>");
  char *iFile = cmd.getArgument(0);
  PhiIO* io = new PhiIO();
  Graph<Vertex> graph = io->loadGraphFromFile(iFile);
  //io->iofree();
  //char *s = (io->readStringFromFile(iFile)).get();
  compute(graph);
  graph.delgraph();

}

#endif
