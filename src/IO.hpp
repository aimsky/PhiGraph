#ifndef IO_H
#define IO_H

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "utils.hpp"
#include "parallel.hpp"
#include "vertex.hpp"
#include "graph.hpp"


using namespace std;

namespace phigraph {

template <class pg>
class seq {
  pg *_v;
  long num;

public:
  pg *get() { return _v; }
  seq() {
    _v = NULL;
    num = 0;
  }
  ~seq(){
    del();
  }
  seq(pg *v, long n) : _v(v), num(n) {}
  void del() { free(_v); }
};

class PhiIO {
public:
  PhiIO() {}

  Graph<Vertex> loadGraphFromFile(char* fileName){
    seq<char> temp = readStringFromFile(fileName);
    char * _string = temp.get();
    //printf("%s\n",_string );
    //temp.del();//set free memory
    //split string by \n
    char * word = strtok (_string,split);
    if(word == (string)"AdjacencyGraph"){
      word = strtok (NULL,split);
      vertexNum = atol(word);
      //printf("vertexNum=%ld\n",vertexNum );
      word = strtok (NULL,split);
      edgeNum = atol(word);
      //printf("edgeNum=%ld\n",edgeNum );

      offset = phimalloc(uphiLong,vertexNum);
      edges = phimalloc(uphiLong,edgeNum);
      #ifdef WEIGHTED
      weight = phimalloc(double,edgeNum);
      #endif
    }
    //set string to long
    for(long i = 0; i < vertexNum; i++){
      word = strtok (NULL,split);
      offset[i] = atol(word);
      //printf("%ld\n",offset[i] );
    }
    for(long i = 0; i < edgeNum; i++){
      word = strtok (NULL,split);
      edges[i] = atol(word);
      //printf("%ld\n",edges[i] );
    }
    #ifdef WEIGHTED
    for(long i = 0; i < edgeNum; i++){
      word = strtok (NULL,split);
      weight[i] = atof(word);
      //printf("%ld ",weight[i] );
    }
    //printf("\n" );
    #endif

    //set vertex
    Vertex* v = phimalloc(Vertex,vertexNum);

    parallel_for (phiLong i=0; i < vertexNum; i++) {
      phiLong start = offset[i];
      phiLong l = ((i == vertexNum-1) ? edgeNum : offset[i+1])-offset[i];
      v[i].setOutDegree(l);
      v[i].setOutVertexes(edges+start);
      #ifdef WEIGHTED
      v[i].setOutWeight(weight+start);
      #endif

    }
    return Graph<Vertex>(v,vertexNum,edgeNum);

  }

  seq<char> readStringFromFile(char *fileName) {
    ifstream file(fileName, ios::in | ios::binary | ios::ate);
    if (!file.is_open()) {
      cout << "Unable to open file: " << fileName << endl;
      abort();
    }
    long end = file.tellg();
    file.seekg(0, ios::beg);
    long n = end - file.tellg();
    char *bytes = phimalloc(char, n + 1);
    file.read(bytes, n);
    file.close();
    return seq<char>(bytes, n);
  }
  void iofree(){
    free(offset);
    free(edges);
  }
private:
  // char * _string;
  // char * word;
  const char * split = "\n\t\r ";
  uphiLong* offset;
  uphiLong* edges;
  //#ifdef WEIGHTED
  double* weight;
  //#endif
  phiLong vertexNum;
  phiLong edgeNum;
};
};

#endif
