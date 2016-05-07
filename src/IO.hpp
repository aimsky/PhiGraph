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
  PhiIO() {
    offset = NULL;
    inEdges = NULL;
    outEdges = NULL;
    split = "\n\t\r ";
  }

  Graph<Vertex> loadGraphFromFile(char* csrfileName,char* cscfileName = NULL){
    seq<char> csr_temp = readStringFromFile(csrfileName);

    char * _string = csr_temp.get();
    //printf("%s\n",_string );
    //temp.del();//set free memory
    //split string by \n

    stringToArray(_string,true);
    //set vertex
    Vertex *v = new Vertex[vertexNum];
    parallel_for (phiLong i=0; i < vertexNum; i++) {
      phiLong start = offset[i];
      phiLong l = ((i == vertexNum-1) ? edgeNum : offset[i+1])-offset[i];
      v[i].setOutDegree(l);
      v[i].setOutVertexes(outEdges+start);
      #ifdef WEIGHTED
      v[i].setOutWeight(outWeight+start);
      #endif
    }
    if(cscfileName != NULL){
      printf("cssfilename=%s\n",cscfileName );
      //temp.del();
      seq<char> csc_temp = readStringFromFile(cscfileName);

      stringToArray(csc_temp.get(),false);
      parallel_for (phiLong i=0; i < vertexNum; i++) {
        phiLong start = offset[i];
        phiLong l = ((i == vertexNum-1) ? edgeNum : offset[i+1])-offset[i];
        v[i].setInDegree(l);
        v[i].setInVertexes(inEdges+start);
        #ifdef WEIGHTED
        v[i].setInWeight(inWeight+start);
        #endif
      }
    }



    return Graph<Vertex>(v,vertexNum,edgeNum);

  }



  void stringToArray(char * _string,bool val){
    char * word = strtok (_string,split);
    uphiLong* _edges = NULL;
    phiDouble* _weight = NULL;

    //get graph vertex num and edges num
    if(word == (string)"AdjacencyGraph"){
      word = strtok (NULL,split);
      vertexNum = atol(word);
      //printf("vertexNum=%ld\n",vertexNum );
      word = strtok (NULL,split);
      edgeNum = atol(word);
      //printf("edgeNum=%ld\n",edgeNum );
      if(offset == NULL)
        offset = phimalloc(uphiLong,vertexNum);
      if(val){
        //offset = phimalloc(uphiLong,vertexNum);
        outEdges = phimalloc(uphiLong,edgeNum);
        #ifdef WEIGHTED
        outWeight = phimalloc(double,edgeNum);
        _weight = outWeight;
        #endif
        _edges = outEdges;

      }else{
        inEdges = phimalloc(uphiLong,edgeNum);
        #ifdef WEIGHTED
        inWeight = phimalloc(double,edgeNum);
        _weight = inWeight;
        #endif
        _edges = inEdges;
      }

    }
    //set string to long
    for(long i = 0; i < vertexNum; i++){
      word = strtok (NULL,split);
      offset[i] = atol(word);
      //printf("%ld\n",offset[i] );
    }
    for(long i = 0; i < edgeNum; i++){
      word = strtok (NULL,split);
      _edges[i] = atol(word);
      //printf("%ld\n",edges[i] );
    }
    #ifdef WEIGHTED
    for(long i = 0; i < edgeNum; i++){
      word = strtok (NULL,split);
      _weight[i] = atof(word);
      //printf("%ld ",weight[i] );
    }
    //printf("\n" );
    #endif
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
    free(outEdges);
  }
private:
  // char * _string;
  // char * word;
  const char * split;
  uphiLong* offset;
  uphiLong* inEdges;
  //#ifdef WEIGHTED
  double* inWeight;

  uphiLong* outEdges;
  //#ifdef WEIGHTED
  double* outWeight;

  // uphiLong* outOffset;
  // uphiLong* edges;
  // //#ifdef WEIGHTED
  // double* weight;

  //#endif
  phiLong vertexNum;
  phiLong edgeNum;
};
};

#endif
