#include "vertex.h"


Vertex::Vertex(){
  //inVertexes = NULL;
  //outVertexes = NULL;
  visited = false;
}
Vertex::Vertex(uphiLong* invertexes,uphiLong* outvertexes,phiLong indegree,phiLong outdegree){
  inVertexes = invertexes;
  outVertexes = outvertexes;
  inDegree = indegree;
  outDegree = outdegree;
  visited = false;
};
uphiLong* Vertex::getInVertexes () {
  return inVertexes;
}
uphiLong* Vertex::getOutVertexes () {
  return outVertexes;
}
uphiLong Vertex::getInVertexes(uphiLong j) {
  return inVertexes[j];
}
uphiLong Vertex::getOutVertexes(uphiLong j) {
  return outVertexes[j];
}
uphiLong Vertex::getOutDegree() {
  return outDegree;
}
uphiLong Vertex::getInDegree() {
  return inDegree;
}
void Vertex::setInVertexes(uphiLong* _i) {
  inVertexes = _i;
}
void Vertex::setOutVertexes(uphiLong* _i) {
  outVertexes = _i;
}
void Vertex::setOutDegree(uphiLong _i) {
  outDegree = _i;
}
void Vertex::setInDegree(phiLong _i) {
  inDegree = _i;
}
void Vertex::setOutWeight(phiDouble* _i){
  outWeight = _i;
}
void Vertex::setInWeight(phiDouble* _i){
  inWeight = _i;
}
phiDouble Vertex::getOutWeight(uphiLong j){
  return outWeight[j];
}
phiDouble Vertex::getInWeight(uphiLong j){
  return inWeight[j];
}
void Vertex::setVisited(){
  visited = true;
}
bool Vertex::isVisited(){
  return visited;
}
Vertex::~Vertex(){
  // if(NULL != inVertexes)
  //   free(inVertexes);
  // if(NULL != outVertexes)
  //   free(outVertexes);
  #ifdef WEIGHTED
  //free(outWeight);
  #endif
  //printf("delete\n");
}
