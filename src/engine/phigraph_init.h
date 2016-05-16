#ifndef PHIGRAPH_INIT_H
#define PHIGRAPH_INIT_H
#include "../utils/command.h"
#include "../io/graph_io.h"
#include "../structure/graph.h"
class PhiGraphInit{
public:
  PhiGraphInit(int argc, char *argv[]);
  Graph<Vertex>& getGraph();
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
