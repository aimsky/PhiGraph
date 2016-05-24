#include "CSR.hpp"
#include "CSC.hpp"
#include "../src/utils/command.h"
#include "../src/io/graph_io.h"
#include <omp.h>

int parallel_main(int argc, char* argv[]) {

  command cmd(argc,argv,"[-s] [-w] [-m <numedges>] [-r <intseed>] [-a <a>] [-b <b>] [-c <c>] n <outFile>");

  printf("%s  %s\n",cmd.getArgument(0),cmd.getArgument(1) );
  //phiLong n = atol(cmd.getArgument(1));
  char* fname = cmd.getArgument(1);
  char* cscfname = cmd.getArgument(2);

  bool hasWeight = cmd.getOption("-w");
  PhiGraphIO* io = new PhiGraphIO(false);



  CSC* csc = new CSC(io->loadGraphFromFile(fname));
  //io->iofree();
  printf("csc\n" );
  uphiLong* s = csc->getOffset();
  // for(long i = 0;i < csc->vertexNum;i++){
  //   printf("%lu\n",s[i] );
  // }
  uphiLong* c = csc->getEdges();
  phiDouble* w;
  if(hasWeight){
    io = new PhiGraphIO(csc->vertexNum,csc->edgesNum,s,c,w);
  }else{
    io = new PhiGraphIO(csc->vertexNum,csc->edgesNum,s,c);
  }
  io->writeGraphToFile(cscfname);


  //delete csr;

}
