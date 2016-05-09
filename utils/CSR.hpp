#ifndef CSR_HPP
#define CSR_HPP
#include "../src/utils.hpp"
#include "../src/parallel.hpp"
#include <vector>
using namespace std;
class CSR{
public:
  CSR(phiLong n ){
    vertexNum = n;
    offset = phimalloc(uphiLong,n);
    outDegree = phimalloc(uphiLong,n);
    weight = NULL;
  }
  uphiLong* getRandomOffset(){
    srand((int)time(NULL));
    offset[0] = 0;
    parallel_for(phiLong i = 0;i < vertexNum;i++){
      outDegree[i] = random<uphiLong>(0,10);
      offset[i+1] = outDegree[i] + offset[i];
    }
    return offset;
  }
  uphiLong* getRandomOutVertex(){
    uphiLong temp = 0;
    srand((int)time(NULL));
    for(phiLong i = 0;i < vertexNum;i++)
      for(uphiLong j = 0;j < outDegree[i];j++){
        temp = random<uphiLong>(0,vertexNum-1,i);
        outVertex.push_back(temp);
      }
    return &outVertex[0];
  }
  phiLong getEdgesNum(){
    return outDegree[vertexNum-1]+offset[vertexNum-1];
  }
  phiDouble* getRandomWeight(){
    srand((int)time(NULL));
    weight = phimalloc(phiDouble,getEdgesNum());
    parallel_for(phiLong i = 0;i < vertexNum;++i){
      weight[i] = random<phiDouble>(0,50);
    }
    return weight;
  }
  ~CSR(){
    free(offset);
    free(outDegree);
    if(weight!= NULL){
      free(weight);
    }
    outVertex.clear();
  }
private:
  phiLong vertexNum;
  phiLong edgesNum;
  uphiLong* offset;
  uphiLong* outDegree;
  phiDouble* weight;
  vector<uphiLong> outVertex;
};


#endif
