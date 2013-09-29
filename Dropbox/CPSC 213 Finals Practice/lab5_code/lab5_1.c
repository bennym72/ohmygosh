#include <stdlib.h>
#include <stdio.h>
/* Initiallize your array and n the same way in 
your data section of youe sm213 code */

int a[] = { 7, 5, 3, 1, 4, 8, 6, 8 };
int n = 8;
int p;

/* Translate the following two functions and the main program */
/* Note: When a function returns a value, 
         it leaves that value in register r0  */ 
void shuffle() {
  int i;
  for(i = 0; i < (n/2); i++) {
	int t = a[i];
	a[i] = a[n - i - 1];
	a[n - i - 1] = t;
  }
}


int pick() {
	int s = (a[n/2] + a[n/4]) / 2;
	return s;
}

void main() {
	shuffle();
	p = pick();
	printf("a[0]:%d\n	a[0]:%d\n	a[0]:%d\n	a[0]:%d\n	a[0]:%d\n	a[0]:%d\n	a[0]:%d\n	a[0]:%d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
	printf("p:%d\n", p);
}
