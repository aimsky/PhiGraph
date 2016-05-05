#ifndef VERTEX_SUBSET_HPP
#define  VERTEX_SUBSET_HPP
#include <stdlib.h>
#include <iostream>
#include "parallel.hpp"
#include "utils.hpp"
#include <vector>
using namespace std;

class VertexSubset{
public:
  long n, m;
  vector<uphiLong> vertex;
  bool* d;
  bool isDense;

  // make a singleton vertex in range of n
  VertexSubset(phiLong _n, uphiLong v): n(_n), m(1), d(NULL), isDense(0) {
    vertex.push_back(v);
    omp_init_lock(&mylock);//omp_init_lock(&mylock);
  }

  //empty vertex set
  VertexSubset(long _n) : n(_n), m(0), d(NULL), isDense(0) {
    omp_init_lock(&mylock);//omp_init_lock(&mylock);

  }
  // make VertexSubset from array of vertex indices
  // n is range, and m is size of array
  VertexSubset(long _n, long _m, uphiLong* indices): n(_n), m(_m), d(NULL), isDense(0) {
    parallel_for(long j = 0;j < m;j++){
      vertex.push_back(indices[j]);
    }
    omp_init_lock(&mylock);//omp_init_lock(&mylock);
  }
  // make VertexSubset from boolean array, where n is range

  //VertexSubset(long _n, long _m, bool* bits): n(_n), m(_m), s(NULL), d(bits), isDense(1)  {}

  void clear(){
    vertex.clear();
    m = 0;
  }
  void add(phiLong s){
    omp_set_lock(&mylock);
    vertex.push_back(s);
    omp_unset_lock(&mylock);//omp_unset_lock(&mylock);
    #pragma omp atomic
    m++;
  }
  // delete the contents
  void del(){
    if (d != NULL) free(d);
    if (!vertex.empty()) vertex.clear();
  }
  long numRows() { return n; }
  long numNonzeros() { return m; }
  bool isEmpty() { return m==0; }
  bool isFull() { return m==n; }
  ~VertexSubset(){
    del();
  }

  // converts to dense but keeps sparse representation if there
  // void toDense() {
  //   if (d == NULL) {
  //     d = phimalloc(bool,n);
  //     {parallel_for(long i=0;i<n;i++) d[i] = 0;}
  //     {parallel_for(long i=0;i<m;i++) d[s[i]] = 1;}
  //   }
  //   isDense = true;
  // }

  // void print() {
  //   if (isDense) {
  //     cout << "D:";
  //     for (long i=0;i<n;i++) if (d[i]) cout << i << " ";
  //     cout << endl;
  //   } else {
  //     cout << "S:";
  //     for (long i=0; i<m; i++)	cout << s[i] << " ";
  //     cout << endl;
  //   }
  // }
private:
  omp_lock_t mylock;  // omp_lock_t mylock

};

#endif
