#ifndef PHIGRAPH_ENGINE_HPP
#define PHIGRAPH_ENGINE_HPP
#include "../api/phigraph_program.h"
#include "../structure/graph.h"
#include "../structure/vertex.h"
#include "../structure/vertexSubset.h"

class PhiGraphEngine{
public:
  PhiGraphEngine(Graph<Vertex>* graph);
  ~PhiGraphEngine();

  VertexSubset* vertexUpdate(Graph<Vertex>& phigraph,VertexSubset* frontier,PhiGraphProgram& app);

  void vertexUpdateSerial(Graph<Vertex>& phigraph,PhiGraphProgram& app);

  void vertexUpdate(Graph<Vertex>& phigraph,PhiGraphProgram& app);

  void exec(PhiGraphProgram& program,VertexSubset* vertexsubset = NULL);
private:
  phiLong iteration;
  Graph<Vertex>* phigraph;

};

#endif
