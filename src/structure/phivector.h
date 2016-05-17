#ifndef PHIVECTOR_H
#define PHIVECTOR_H
#include "../api/phigraph_aligned.h"
#include <math.h>
template <class Type>
class PhiVector{
public:
  phiLong length;

  PhiVector(phiLong dataNum){
    x = 64/sizeof(Type);
    y = ceil(dataNum/x);
    array = phimalloc(Type*,y);
    for(phiLong i = 0;i < y;i++){
      array[i] = phimalloc(Type,x);
    }
    index = 0;
  }
  void insert(Type value){
    if(index < length){
      array[index] = value;
      index++;
    }
  }
  void insert(Type* value){
    array = value;
  }
private:
  Type** array;
  phiLong x;
  phiLong y;
  phiLong index;

};

#endif
