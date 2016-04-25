#ifndef CORE_HPP
#define CORE_HPP

#include "IO.hpp"
#include "command.hpp"
#include <stdio.h>
using namespace phigraph;

void Compute(Graph<Vertex> phigraph);

int parallel_main(int argc, char *argv[]) {
  command cmd(argc, argv, " [-s] <inFile>");
  char *iFile = cmd.getArgument(0);
  PhiIO* io = new PhiIO();
  Graph<Vertex> graph = io->loadGraphFromFile(iFile);
  io->iofree();
  //char *s = (io->readStringFromFile(iFile)).get();
  Compute(graph);
  graph.delgraph();

}

#endif
