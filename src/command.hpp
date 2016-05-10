/*
resolve commandLine
*/

#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct command {
  int argc;
  char **argv;
  string comLine;
  command(int _c, char **_v, string _cl)
      : argc(_c), argv(_v), comLine(_cl) {}

  command(int _c, char **_v)
      : argc(_c), argv(_v), comLine("bad arguments") {}

  void badArgument() {
    cout << "usage: " << argv[0] << " " << comLine << endl;
    abort();
  }

  // get an argument
  // i is indexed from the last argument = 0, second to last indexed 1, ..
  char *getArgument(int i) {
    // if (argc < 1 + i)
    //   badArgument();
    //return argv[argc - 1 - i];
    return argv[i];
  }

  // looks for two filenames
  pair<char *, char *> IOFileNames() {
    if (argc < 3)
      badArgument();
    return pair<char *, char *>(argv[argc - 2], argv[argc - 1]);
  }

  pair<int, char *> sizeAndFileName() {
    if (argc < 3)
      badArgument();
    return pair<int, char *>(atoi(argv[argc - 2]), (char *)argv[argc - 1]);
  }

  bool getOption(string option) {
    for (int i = 1; i < argc; i++)
      if ((string)argv[i] == option)
        return true;
    return false;
  }

  char *getOptionValue(string option) {
    for (int i = 1; i < argc - 1; i++)
      if ((string)argv[i] == option)
        return argv[i + 1];
    return NULL;
  }

  string getOptionValue(string option, string defaultValue) {
    for (int i = 1; i < argc - 1; i++)
      if ((string)argv[i] == option)
        return (string)argv[i + 1];
    return defaultValue;
  }

  int getOptionIntValue(string option, int defaultValue) {
    for (int i = 1; i < argc - 1; i++)
      if ((string)argv[i] == option) {
        int r = atoi(argv[i + 1]);
        return r;
      }
    return defaultValue;
  }

  long getOptionLongValue(string option, long defaultValue) {
    for (int i = 1; i < argc - 1; i++)
      if ((string)argv[i] == option) {
        long r = atol(argv[i + 1]);
        return r;
      }
    return defaultValue;
  }

  double getOptionDoubleValue(string option, double defaultValue) {
    for (int i = 1; i < argc - 1; i++)
      if ((string)argv[i] == option) {
        double val;
        if (sscanf(argv[i + 1], "%lf", &val) == EOF) {
          badArgument();
        }
        return val;
      }
    return defaultValue;
  }
};

#endif
