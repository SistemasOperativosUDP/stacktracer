#include <stdio.h>
#include "traceback.h"

void foo(char** string_array) {
  traceback(stdout);
}

int main (int argc, char **argv)
{
  char * sap[] = {'a', "abcdefghijklmnopqrstuvwxyz", "abc\1de"};
  foo(sap);
  return 0;
}
