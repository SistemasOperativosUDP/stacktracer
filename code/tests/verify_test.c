/** @file verify_test.c
 *
 * Test output format for the traceback function
 *
 * This test calls a few functions to test a bunch
 * of different outputs.
 *
 * @author Michael Ashley-Rollman(mpa)
 */

#include "traceback.h"

void f8(int i, char** f)
{
  traceback(stdout);
}

/*void f7(int p,int g, int j, int l)
{
	char r = (char)5;
	char d = (char)6;
	char s[] = {r,d};
	char *arg[] = {"foo", "bar", "baz", "bletch"};
  	arg[2] = s;
  	f8(5, arg);
}

void f6(char* gato)
{
  f7(6,7,8,8);
}

void f5(double array)
{
  f6("abcdefghijklmnopqrstuvwxyza");
}

void f4(int i, float f, void* k)
{
  f5(453e93);
}

void f3(int p, char g, char l)
{
  int k = 5;
  void* j = &k;
  f4(5, 35.0,j);
}

void f2(void)
{
  char j = (char)6;
  f3(6, 'f',j);
}

void f1(char ** array)
{
  f2();
}
*/
int main()
{
  char *arg[] = {"foo", "bar"};

  f8(5,arg);

  return 0;
}
