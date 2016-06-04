#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <malloc.h>
#include <mm_malloc.h>
#include <iostream>
#include <omp.h>
#include "../structure/phivector.h"
//dynamic memorry aligned
#define phimalloc(_n, _m) (_n *)_mm_malloc(_m*sizeof(_n),64)


typedef __attribute__((align(64))) long phiLong;
typedef __attribute__((align(64))) unsigned long uphiLong;
typedef __attribute__((align(64))) double phiDouble;
#define INT_T_MAX LONG_MAX
#define UINT_T_MAX ULONG_MAX

//random
template<class T>
T random(int m, int n)
{
        int pos, dis;
        if(m == n)
        {
            return (T)m;
        }
        else if(m > n)
        {
            pos = n;
            dis = m - n + 1;
            return (T)(rand() % dis + pos);
        }
        else
        {
            pos = m;
            dis = n - m + 1;
            return (T)(rand() % dis + pos);
        }
}
template <class T>
T random(int m,int n,int limit){
  //if(limit == random(m,n))
  T temp;
  do{
    temp = random<T>(m,n);
  }while(limit == temp);
  return temp;
}

//atomic operation
template <class ET>
inline bool phiCAS(ET *ptr, ET oldv, ET newv) {
  if (sizeof(ET) == 1) {
    return __sync_bool_compare_and_swap((bool*)ptr, *((bool*)&oldv), *((bool*)&newv));
  } else if (sizeof(ET) == 4) {
    return __sync_bool_compare_and_swap((int*)ptr, *((int*)&oldv), *((int*)&newv));
  } else if (sizeof(ET) == 8) {
    return __sync_bool_compare_and_swap((long*)ptr, *((long*)&oldv), *((long*)&newv));
  }else {
    std::cout << "CAS bad length : " << sizeof(ET) << std::endl;
    abort();
  }
}
inline phiDouble simd_sum(PhiVector<phiDouble>* vec){
  phiDouble sum[8] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
  #pragma prefetch vec->array
  #pragma simd
  for(phiLong i =0;i < vec->y;i++){
    #pragma prefetch vec->array[i]:2:8
    sum[0] += vec->array[i][0];
    sum[1] += vec->array[i][1];
    sum[2] += vec->array[i][2];
    sum[3] += vec->array[i][3];
    sum[4] += vec->array[i][4];
    sum[5] += vec->array[i][5];
    sum[6] += vec->array[i][6];
    sum[7] += vec->array[i][7];
  }
  return sum[0]+sum[1]+sum[2]+sum[3]+sum[4]+sum[5]+sum[6]+sum[7];
}

template <class ET>
inline bool writeMin(ET *a, ET b) {
  ET c; bool r=0;
  do c = *a;
  while (c > b && !(r=phiCAS(a,c,b)));
  return r;
}

template <class ET>
inline void writeAdd(ET *a, ET b) {
  volatile ET newV, oldV;
  do {oldV = *a; newV = oldV + b;}
  while (!phiCAS(a, oldV, newV));
}


static int machine_core_num = omp_get_num_procs();
static int MIN_ITERATION_NUM = 4;
//dynamic set threads num
inline int dynamicThreadNum(int n,int min_each = MIN_ITERATION_NUM,int core_num = machine_core_num){
  int max_tn = n/min_each;
  int tn = max_tn > core_num? core_num:max_tn;
  if(tn < 1){
    tn = 1;
  }
  return tn;
}



#endif
