#ifndef IO_H
#define IO_H

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include "utils.hpp"
#include "parallel.hpp"


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
  seq(pg *v, long n) : _v(v), num(n) {}
  void del() { free(_v); }
};

class PhiIO {
public:
  PhiIO() {}

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
};
};
#endif
