
#ifndef GETTIME_H
#define GETTIME_H

#include <stdlib.h>
#include <sys/time.h>
#include <iomanip>
#include <iostream>

class Timer {
public:

  Timer() ;
  double getTime() ;
  void start () ;
  double stop () ;
  double stop (double weight);

  double total();

  double next();

  void reportT(double time);

  void reportTime(double time);

  void reportStop(double weight, std::string str);

  void reportTotal();

  void reportTotal(std::string str);
  void reportNext();

  void reportNext(std::string str);

private:
  double totalTime;
  double lastTime;
  double totalWeight;
  bool on;
  struct timezone tzp;
};


#endif
