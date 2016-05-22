#ifndef VERTEX_SUBSET_H
#define  VERTEX_SUBSET_H
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include "../utils/parallel.h"
#include "../utils/utils.h"

using namespace std;

class VertexSubset{
public:

  long n, m;
  vector<uphiLong> vertex;
  bool* d;
  bool isDense;
  // make a singleton vertex in range of n
  VertexSubset(phiLong _n, uphiLong v);
  //empty vertex set
  VertexSubset(long _n);
  // make VertexSubset from array of vertex indices
  // n is range, and m is size of array
  VertexSubset(long _n, long _m, uphiLong* indices);
  // make VertexSubset from boolean array, where n is range

  //VertexSubset(long _n, long _m, bool* bits): n(_n), m(_m), s(NULL), d(bits), isDense(1)  {}

  void clear();
  void add(phiLong s);
  // delete the contents
  void del();
  long numRows();
  long numNonzeros();
  bool isEmpty();
  bool isFull();
  ~VertexSubset();

private:
  // int lock;
  // int unlock;
  // int mutex;
  omp_lock_t mylock;


};

#endif
