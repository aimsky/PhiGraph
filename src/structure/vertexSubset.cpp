#include "vertexSubset.h"


// make a singleton vertex in range of n
VertexSubset::VertexSubset(phiLong _n, uphiLong v): n(_n), m(1), d(NULL), isDense(0) {
  // lock = 0;
  // mutex = 0;
  // unlock = 1;
  vertex.push_back(v);
  omp_init_lock(&mylock);//omp_init_lock(&mylock);
}

//full vertex set
VertexSubset::VertexSubset(long _n) : n(_n), m(0), d(NULL), isDense(0) {
  // lock = 0;
  // mutex = 0;
  // unlock = 1;
  omp_init_lock(&mylock);
}
// make VertexSubset from array of vertex indices
// n is range, and m is size of array
VertexSubset::VertexSubset(long _n, long _m, uphiLong* indices): n(_n), m(_m), d(NULL), isDense(0) {
  parallel_for(long j = 0;j < m;j++){
    vertex.push_back(indices[j]);
  }
  omp_init_lock(&mylock);
}
// make VertexSubset from boolean array, where n is range

//VertexSubset(long _n, long _m, bool* bits): n(_n), m(_m), s(NULL), d(bits), isDense(1)  {}

void VertexSubset::clear(){
  vertex.clear();
  m = 0;
}
void VertexSubset::add(phiLong s){
  omp_set_lock(&mylock);
  //while (!(phiCAS(&mutex,lock, 1) ))
  //usleep(10);
  vertex.push_back(s);

  //phiCAS(&mutex, unlock, 0);

  omp_unset_lock(&mylock);//omp_unset_lock(&mylock);
  #pragma omp atomic
  m++;

}
// delete the contents
void VertexSubset::del(){
  if (d != NULL) free(d);
  if (!vertex.empty()) vertex.clear();
  omp_destroy_lock(&mylock);
}
long VertexSubset::numRows() { return n; }
long VertexSubset::numNonzeros() { return m; }
bool VertexSubset::isEmpty() { return m==0; }
bool VertexSubset::isFull() { return m==n; }
VertexSubset::~VertexSubset(){
  del();
}
