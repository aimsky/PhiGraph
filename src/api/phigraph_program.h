#ifndef PHIGRAPH_PROGRAM_H
#define PHIGRAPH_PROGRAM_H
#include "../utils/utils.h"
#include "../structure/graph.h"
#include "../structure/vertex.h"
#include "../structure/vertexSubset.h"
class PhiGraphProgram{
public:
  PhiGraphProgram(){};

  virtual void update(Graph<Vertex>& phigraph,VertexSubset* nextFrontier,uphiLong curVertex){};
  virtual void update(Graph<Vertex>& phigraph,uphiLong curVertex){};
  virtual void gather(){};
  virtual void apply(){};
  virtual void setter(){};
  /**
   * Called before an iteration starts.
   */
  virtual bool before_iteration(int iteration,VertexSubset* vertexsubset) {
    return true;
  }
  virtual bool before_iteration(int iteration) {
    return true;
  }

  /**
   * Called after an iteration has finished.
   */
  virtual bool after_iteration(int iteration,VertexSubset* vertexsubset) {
    return true;
  }
  virtual bool after_iteration(int iteration) {
    return true;
  }

  /**
   * Called after an compution has finished.
   */
  virtual void compution_finish() {
  }

};
#endif