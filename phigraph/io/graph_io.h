#ifndef PHIGRAPH_IO_H
#define PHIGRAPH_IO_H
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "seq.h"
#include "../structure/graph.h"
#include "../structure/vertex.h"
#include "../utils/parallel.h"
#include "../utils/utils.h"

using namespace std;

class PhiGraphIO {
public:
  PhiGraphIO(bool w);
  PhiGraphIO(phiLong vn,phiLong en,uphiLong* o,uphiLong* out,phiDouble* outw = NULL);
  void writeGraphToFile(char* filename);
  Graph<Vertex>* loadGraphFromFile(char* csrfileName,char* cscfileName = NULL);
  void stringToArray(char * _string,bool val);
  seq<char> readStringFromFile(char *fileName);
  void iofree();
private:
  bool weighted;
  const char * split;
  uphiLong* offset;
  uphiLong* inEdges;
  //#ifdef WEIGHTED
  double* inWeight;

  uphiLong* outEdges;
  //#ifdef WEIGHTED
  double* outWeight;

  phiLong vertexNum;
  phiLong edgeNum;
};
#endif
