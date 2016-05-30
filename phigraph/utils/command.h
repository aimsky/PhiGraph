#ifndef COMMAND_H
#define COMMAND_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class command {
public:
  command(int _c, char **_v, string _cl);
  command(int _c, char **_v);
  void badArgument();

  // get an argument
  // i is indexed from the last argument = 0, second to last indexed 1, ..
  char *getArgument(int i);
  

  bool getOption(string option);

  char *getOptionValue(string option);

  string getOptionValue(string option, string defaultValue);
  int getOptionIntValue(string option, int defaultValue);

  long getOptionLongValue(string option, long defaultValue);
  double getOptionDoubleValue(string option, double defaultValue);
private:
  int argc;
  char **argv;
  string rightCmdLine;
};

#endif
