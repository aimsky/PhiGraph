#ifndef PHIGRAPH_ENGINE_HPP
#define PHIGRAPH_ENGINE_HPP
#include "../api/phigraph_program.h"
#include "../structure/graph.h"
#include "../structure/vertex.h"
#include "../structure/vertexSubset.h"
#include "../utils/gettime.h"
#include "../structure/phivector.h"
#include "../api/parallel.h"
#include <omp.h>
class PhiGraphEngine{
public:
  PhiGraphEngine(Graph<Vertex>* graph);
  ~PhiGraphEngine();

  VertexSubset* vertexUpdate(Graph<Vertex>& phigraph,VertexSubset* frontier,PhiGraphProgram& app);


  void vertexUpdate(Graph<Vertex>& phigraph,PhiGraphProgram& app,bool parallel);

  void exec_vertex(PhiGraphProgram& program,VertexSubset* vertexsubset);
  void exec_vertex(PhiGraphProgram& program,bool parallel,int iteration = 1);
  void exec_gas(PhiGraphProgram& program);
  void engine_infor(int id);

private:
  phiLong iteration;
  Graph<Vertex>* phigraph;
  Timer* _tm;
  static int MIN_ITERATION_NUM;
  int machine_core_num;
  int threadNum;
  phiDouble running_time;
};

#endif
