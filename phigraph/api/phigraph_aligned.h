#ifndef PHIGRAPH_ALIGNED_H
#define PHIGRAPH_ALIGNED_H
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

#endif
