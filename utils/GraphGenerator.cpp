#include "CSR.hpp"
#include "../src/command.hpp"
#include "../src/IO.hpp"
using namespace phigraph;
int parallel_main(int argc, char* argv[]) {

  command cmd(argc,argv,"[-s] [-m <numedges>] [-r <intseed>] [-a <a>] [-b <b>] [-c <c>] n <outFile>");

  printf("%s  %s\n",cmd.getArgument(0),cmd.getArgument(1) );
  phiLong n = atol(cmd.getArgument(1));
  char* fname = cmd.getArgument(0);

  CSR* csr = new CSR(n);
  uphiLong* s = csr->getRandomOffset();
  uphiLong* c = csr->getRandomOutVertex();
  PhiIO* io = new PhiIO(n,csr->getEdgesNum(),s,c);
  io->writeGraphToFile(fname);

}
