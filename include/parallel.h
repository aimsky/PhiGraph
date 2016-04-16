
#ifndef _PARALLEL_H
#define _PARALLEL_H

// openmp
#ifndef defined(OPENMP)
#include <omp.h>
#define parallel_main main
#define parallel_for _Pragma("omp parallel for") for
#define parallel_for_1 _Pragma("omp parallel for schedule (static,1)") for
#define parallel_for_256 _Pragma("omp parallel for schedule (static,256)") for

#endif



#endif // _PARALLEL_H
