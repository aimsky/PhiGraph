#ifndef CSC_HPP
#define CSC_HPP
#include "../src/utils/utils.h"
#include "../src/utils/parallel.h"
#include "../src/structure/graph.h"
#include "../src/structure/vertex.h"
#include <vector>
using namespace std;
class CSC{

public:
  Graph<Vertex>* phigraph;
  phiLong* inDegree;
  uphiLong* offset;
  uphiLong* edges;
  phiLong* index;
  phiLong vertexNum;
  phiLong edgesNum;
  CSC(Graph<Vertex>* graph){
    phigraph = graph;
    vertexNum = graph->vertexNum;
    edgesNum = graph->edgeNum;
    inDegree = phimalloc(phiLong,graph->vertexNum);
    parallel_for(phiLong i = 0;i < vertexNum;i++){
      inDegree[i] = 0;
    }
    offset = phimalloc(uphiLong,graph->vertexNum);
    edges = phimalloc(uphiLong,graph->edgeNum);
    index = phimalloc(phiLong,graph->vertexNum);
    parallel_for(phiLong i = 0;i < vertexNum;i++){
      index[i] = 0;
    }
  }
  uphiLong* getOffset(){
    parallel_for(phiLong i = 0;i < vertexNum;i++){
      phiLong outDegree = phigraph->vertex[i].getOutDegree();
      for(phiLong j = 0;j < outDegree;j++){
        phiLong temp = phigraph->vertex[i].getOutVertexes(j);
        #pragma omp atomic
        inDegree[temp]++;
      }

    }
    offset[0] = 0;
    for(phiLong i = 0;i < vertexNum;i++){
      if(i != (vertexNum-1))
        offset[i+1] = offset[i] + inDegree[i];
    }
    //printf("ooff\n");
    return offset;
  }
  uphiLong* getEdges(){
    for(phiLong i = 0;i < vertexNum;i++){
      phiLong outDegree = phigraph->vertex[i].getOutDegree();
      for(phiLong j = 0;j < outDegree;j++){
        phiLong temp = phigraph->vertex[i].getOutVertexes(j);
        edges[offset[temp]+index[temp]] = i;
        index[temp]++;
      }

    }
    return edges;
    //printf("edges\n" );
  }


};
#endif
