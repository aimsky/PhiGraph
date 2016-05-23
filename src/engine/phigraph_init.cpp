#include "phigraph_init.h"

PhiGraphInit::PhiGraphInit(int argc, char *argv[]){
  cmd = new command(argc, argv, " [-s] <inFile>");
  csrFile = cmd->getArgument(1);
  cscFile = cmd->getOptionValue("-c");
  bool weighted = cmd->getOption("-w");
  graphIO = new PhiGraphIO(weighted);
  graph = graphIO->loadGraphFromFile(csrFile,cscFile);
  delete cmd;
}
Graph<Vertex>& PhiGraphInit::getGraph(){
  return *graph;
}
PhiGraphInit::~PhiGraphInit(){
  delete graphIO;

}
