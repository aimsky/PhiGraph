#ifndef PHIGRAPH_ENGINE_HPP
#define PHIGRAPH_ENGINE_HPP
#include "../api/phigraph_program.h"
#include "../structure/graph.h"
#include "../structure/vertex.h"
#include "../structure/vertexSubset.h"
#include "../utils/gettime.h"
#include "../structure/phivector.h"
#include "../api/parallel.h"
class PhiGraphEngine{
public:
  PhiGraphEngine(Graph<Vertex>* graph);
  ~PhiGraphEngine();

  VertexSubset* vertexUpdate(Graph<Vertex>& phigraph,VertexSubset* frontier,PhiGraphProgram& app);


  void vertexUpdate(Graph<Vertex>& phigraph,PhiGraphProgram& app);

  void exec_vertex(PhiGraphProgram& program,VertexSubset* vertexsubset);
  void exec_vertex(PhiGraphProgram& program,int iteration = 1);
  void exec_gas(PhiGraphProgram& program);

private:
  phiLong iteration;
  Graph<Vertex>* phigraph;
  static Timer* _tm;
  static int MIN_ITERATION_NUM;
  int machine_core_num;
};

#endif
