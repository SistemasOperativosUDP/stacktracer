#include <stdio.h>
#include "traceback.h"

void foo(char c, char* s, char* un) {
  printf("hello from foo\n");
  traceback(stderr);
}

int main (int arg, char **args)
{
  foo('\6', "abcdefghijklmnopqrstuvwxyz", "abc\1de");
  return 0;
}

