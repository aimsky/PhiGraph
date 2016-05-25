
#include "gettime.h"
Timer::Timer() {
  struct timezone tz = {0, 0};
  totalTime=0.0;
  totalWeight=0.0;
  on=0;
  tzp = tz;
}
double Timer::getTime() {
  timeval now;
  gettimeofday(&now, &tzp);
  return ((double) now.tv_sec) + ((double) now.tv_usec)/1000000.;
}
void Timer::start () {
  on = 1;
  lastTime = getTime();
}
double Timer::stop () {
  on = 0;
  double d = (getTime()-lastTime);
  totalTime += d;
  return d;
}
double Timer::stop(double weight) {
  on = 0;
  totalWeight += weight;
  double d = (getTime()-lastTime);
  totalTime += weight*d;
  return d;
}

double Timer::total() {
  if (on) return totalTime + getTime() - lastTime;
  else return totalTime;
}

double Timer::next() {
  if (!on) return 0.0;
  double t = getTime();
  double td = t - lastTime;
  totalTime += td;
  lastTime = t;
  return td;
}

void Timer::reportT(double time) {
  std::cout << std::setprecision(3) << time <<  std::endl;;
}

void Timer::reportTime(double time) {
  reportT(time);
}

void Timer::reportStop(double weight, std::string str) {
  std::cout << str << " :" << weight << ": ";
  reportTime(stop(weight));
}

void Timer::reportTotal() {
  double to = (totalWeight > 0.0) ? total()/totalWeight : total();
  reportTime(to);
  totalTime = 0.0;
  totalWeight = 0.0;
}

void Timer::reportTotal(std::string str) {
  std::cout << str << " : ";
  reportTotal();}

void Timer::reportNext() {reportTime(next());}

void Timer::reportNext(std::string str) {std::cout << str << " : "; reportNext();}
