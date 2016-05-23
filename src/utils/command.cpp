#include "command.h"
command::command(int _c, char **_v, string _cl)
    : argc(_c), argv(_v), rightCmdLine(_cl) {}

command::command(int _c, char **_v)
    : argc(_c), argv(_v), rightCmdLine("bad arguments") {}

void command::badArgument() {
  cout << "usage: " << argv[0] << " " << rightCmdLine << endl;
  abort();
}

// get an argument
// i is indexed from the last argument = 0, second to last indexed 1, ..
char *command::getArgument(int i) {
  if (argc < 1 + i)
    return NULL;
    //badArgument();
  //return argv[argc - 1 - i];
  return argv[i];
}

// looks for two filenames
pair<char *, char *> command::IOFileNames() {
  if (argc < 3)
    badArgument();
  return pair<char *, char *>(argv[argc - 2], argv[argc - 1]);
}

pair<int, char *> command::sizeAndFileName() {
  if (argc < 3)
    badArgument();
  return pair<int, char *>(atoi(argv[argc - 2]), (char *)argv[argc - 1]);
}

bool command::getOption(string option) {
  for (int i = 1; i < argc; i++)
    if ((string)argv[i] == option)
      return true;
  return false;
}

char *command::getOptionValue(string option) {
  for (int i = 1; i < argc - 1; i++)
    if ((string)argv[i] == option)
      return argv[i + 1];
  return NULL;
}

string command::getOptionValue(string option, string defaultValue) {
  for (int i = 1; i < argc - 1; i++)
    if ((string)argv[i] == option)
      return (string)argv[i + 1];
  return defaultValue;
}

int command::getOptionIntValue(string option, int defaultValue) {
  for (int i = 1; i < argc - 1; i++)
    if ((string)argv[i] == option) {
      int r = atoi(argv[i + 1]);
      return r;
    }
  return defaultValue;
}

long command::getOptionLongValue(string option, long defaultValue) {
  for (int i = 1; i < argc - 1; i++)
    if ((string)argv[i] == option) {
      long r = atol(argv[i + 1]);
      return r;
    }
  return defaultValue;
}

double command::getOptionDoubleValue(string option, double defaultValue) {
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
