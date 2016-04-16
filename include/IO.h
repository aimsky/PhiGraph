#ifndef DEF_IO_H
#define DEF_IO_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "parallel.h"

#include <malloc.h>


#define phimalloc(_n,_m) (_n*) malloc((_m)*sizeof(_n))
using namespace std;

namespace phigraph{
	template <class pg>
	class seq {
		pg* _v;
		long num;
		
		
		public:
		 pg* get() {return _v;}
		 seq() {_v = NULL; num=0;}
		 seq(pg* v, long n) : _v(v), num(n) {}
		 void del() {free(_v);}
	};
	class PhiIO{
		public:
		PhiIO(){

		}

		seq<char> readStringFromFile(char *fileName) {
			ifstream file (fileName, ios::in | ios::binary | ios::ate);
			if (!file.is_open()) {
				cout << "Unable to open file: " << fileName << endl;
				abort();
			}
			long end = file.tellg();
			file.seekg (0, ios::beg);
			long n = end - file.tellg();
			char* bytes = phimalloc(char,n+1);
			file.read (bytes,n);
			file.close();
			return seq<char>(bytes,n);
		}
	};

	

	

	
};
#endif