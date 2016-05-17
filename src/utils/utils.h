#ifndef UTILS_HPP
#define UTILS_HPP
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <malloc.h>
#include <mm_malloc.h>

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

#endif
