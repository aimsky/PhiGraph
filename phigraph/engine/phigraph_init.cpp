#include "phigraph_init.h"

PhiGraphInit::PhiGraphInit(int argc, char *argv[]){
  cmd = new command(argc, argv, " [-s] <inFile>");
  csrFile = cmd->getArgument(1);
  cscFile = cmd->getOptionValue("-c");
  bool weighted = cmd->getOption("-w");
  printInfor(0);
  graphIO = new PhiGraphIO(weighted);
  graph = graphIO->loadGraphFromFile(csrFile,cscFile);
  printInfor(1);
  delete cmd;
}
Graph<Vertex>& PhiGraphInit::getGraph(){
  return *graph;
}
void PhiGraphInit::printInfor(int id){
  if(id == 0){
    printf("system is initing\n");
  }else if(id == 1){
    printf("Load graph successfully\n");
    printf("vertex num:[%ld];edges num:[%ld] \n",graph->vertexNum,graph->edgeNum );
  }
}
PhiGraphInit::~PhiGraphInit(){
  delete graphIO;

}
