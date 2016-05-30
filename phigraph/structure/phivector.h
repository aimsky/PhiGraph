#ifndef PHIVECTOR_H
#define PHIVECTOR_H
#include "../api/phigraph_aligned.h"
#include <math.h>
template <class Type>
class PhiVector{
public:
  phiLong length;
  phiLong x;
  phiLong y;
  phiLong index;
  Type** array;
  PhiVector(phiLong dataNum){
    length = dataNum;
    x = 64/sizeof(Type);
    y = ceil((phiDouble)dataNum/x);
    array = phimalloc(Type*,y);
    for(phiLong i = 0;i < y;i++){
      array[i] = phimalloc(Type,x);
    }
    for(phiLong i = 0;i < y;i++){
      for(phiLong j = 0;j < x;j++)
      array[i][j] = (Type)0;
    }
    // printf("x= %d,y=%d\n",x,y );
    // printf("vector\n" );
    index = 0;
  }
  void insert(Type value){
    //printf("index=%d\n",index );
    if(index < length){
      phiLong x_temp = index/x;
      phiLong y_temp = index%x;
      array[x_temp][y_temp] = value;
      #pragma omp atmoic
      index++;
    }
    //printf("got22\n" );
  }
  ~PhiVector(){
    for(phiLong i=0;i < y; i++)
      free(array[i]);

    free(array);
  }

};

#endif
