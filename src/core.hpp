#ifndef CORE_HPP
#define CORE_HPP

#include "IO.hpp"
#include "command.hpp"
#include <stdio.h>
using namespace phigraph;

void Compute(char *s);

int parallel_main(int argc, char *argv[]) {
  command cmd(argc, argv, " [-s] <inFile>");
  char *iFile = cmd.getArgument(0);
  PhiIO *io = new PhiIO();
  char *s = (io->readStringFromFile(iFile)).get();
  Compute(s);
}

#endif
