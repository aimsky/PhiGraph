#ifndef SEQ_H
#define SEQ_H

#include <stdlib.h>

template <class pg>
class seq {

public:
  pg *get(){ return _v; };
  seq(){
    _v = NULL;
    num = 0;
  };
  ~seq(){
    del();
  };
  seq(pg *v, long n) : _v(v), num(n) {};
  void del(){ free(_v); };
private:
  pg *_v;
  long num;
};

#endif
