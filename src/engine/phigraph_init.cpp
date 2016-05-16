#include "phigraph_init.h"

PhiGraphInit::PhiGraphInit(int argc, char *argv[]){
  cmd = new command(argc, argv, " [-s] <inFile>");
  csrFile = cmd->getArgument(1);
  graphIO = new PhiGraphIO();
  graph = graphIO->loadGraphFromFile(csrFile);
  delete cmd;
}
Graph<Vertex>& PhiGraphInit::getGraph(){
  return *graph;
}
PhiGraphInit::~PhiGraphInit(){
  delete graphIO;

}
