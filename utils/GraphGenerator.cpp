#include "CSR.hpp"
#include "CSC.hpp"
#include "../src/utils/command.h"
#include "../src/io/graph_io.h"
#include <omp.h>

int parallel_main(int argc, char* argv[]) {

  command cmd(argc,argv,"[-s] [-w] [-m <numedges>] [-r <intseed>] [-a <a>] [-b <b>] [-c <c>] n <outFile>");

  printf("%s  %s\n",cmd.getArgument(0),cmd.getArgument(1) );
  phiLong n = atol(cmd.getArgument(1));
  char* fname = cmd.getArgument(2);
  char* cscfname = cmd.getArgument(3);

  bool hasWeight = cmd.getOption("-w");

  CSR* csr = new CSR(n);
  uphiLong* s = csr->getRandomOffset();
  uphiLong* c = csr->getRandomOutVertex();
  PhiGraphIO* io;
  phiDouble* w = csr->getRandomWeight();
  if(hasWeight){

    io = new PhiGraphIO(n,csr->getEdgesNum(),s,c,w);
  }else{
    io = new PhiGraphIO(n,csr->getEdgesNum(),s,c);
  }
  // for(uphiLong i = 0;i < csr->getEdgesNum();i++)
  //   printf("%f\n",w[i] );
  //phiDouble xx = random<phiDouble>(1,50);;


  io->writeGraphToFile(fname);
  free(s);
  free(c);
  CSC* csc = new CSC(io->loadGraphFromFile(fname));
  io->iofree();
  s = csc->getOffset();
  c = csc->getEdges();
  if(hasWeight){

    io = new PhiGraphIO(n,csr->getEdgesNum(),s,c,w);
  }else{
    io = new PhiGraphIO(n,csr->getEdgesNum(),s,c);
  }
  io->writeGraphToFile(cscfname);


  //delete csr;

}
