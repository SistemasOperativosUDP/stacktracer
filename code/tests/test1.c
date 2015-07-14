/** 
 * Recursion problem test1
 */

#include <stdio.h>
#include "traceback.h"
int factorial(int n) {
    if (n < 2) {
	traceback(stdout);
    } else {
	return n * factorial(n-1);
    }
}

int main() {
    int num;
    num = 5;
    printf("factorial: %d\n", factorial(num));
    return 0;
}

