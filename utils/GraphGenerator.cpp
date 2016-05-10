#include "CSR.hpp"
#include "../src/command.hpp"
#include "../src/IO.hpp"
using namespace phigraph;
int parallel_main(int argc, char* argv[]) {

  command cmd(argc,argv,"[-s] [-w] [-m <numedges>] [-r <intseed>] [-a <a>] [-b <b>] [-c <c>] n <outFile>");

  printf("%s  %s\n",cmd.getArgument(0),cmd.getArgument(1) );
  phiLong n = atol(cmd.getArgument(1));
  char* fname = cmd.getArgument(2);

  bool hasWeight = cmd.getOption("-w");

  CSR* csr = new CSR(n);
  uphiLong* s = csr->getRandomOffset();
  uphiLong* c = csr->getRandomOutVertex();
  PhiIO* io;
  phiDouble* w = csr->getRandomWeight();
  if(hasWeight){

    io = new PhiIO(n,csr->getEdgesNum(),s,c,w);
  }else{
    io = new PhiIO(n,csr->getEdgesNum(),s,c);
  }
  // for(uphiLong i = 0;i < csr->getEdgesNum();i++)
  //   printf("%f\n",w[i] );
  //phiDouble xx = random<phiDouble>(1,50);;


  io->writeGraphToFile(fname);

  io->iofree();
  //delete csr;

}
