#ifndef PHIGRAPH_INIT_H
#define PHIGRAPH_INIT_H
#include "../utils/command.h"
#include "../io/graph_io.h"
#include "../structure/graph.h"
class PhiGraphInit{
public:
  PhiGraphInit(int argc, char *argv[]);
  Graph<Vertex>& getGraph();
  void printInfor(int id){
    if(id == 0){
      printf("system is initing\n");
    }else if(id == 1){
      printf("Load graph successfully\n");
      printf("vertex num:[%ld];edges num:[%ld] \n",graph->vertexNum,graph->edgeNum );
    }
  }
  ~PhiGraphInit();
private:
  Graph<Vertex>* graph;
  PhiGraphIO* graphIO;
  command* cmd;
  char* csrFile;
  char* cscFile;
  int argc;
  char **argv;
};

#endif
