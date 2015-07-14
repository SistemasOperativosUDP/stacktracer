#include <stdio.h>
#include "traceback.h"

void foo(int ** sap) {
  traceback(stdout);
}
 
int main (int argc, char **argv)
{
  int * iap[] = {123, 345,678};
  foo(iap);
  return 0;
}
