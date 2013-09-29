#include <stdlib.h>
#include <stdio.h>

int a = 40000;
int b = 0;
int c = 3500;
int i = 0;
int g = 0;
int r = 0;

void fun() {
	i = 8;
	while (i != 0) {
		b = b << 1;
		b+= (1 & (a >> 3));
		a = a << 1;
		if (c > b) {
			a++;
			b = b - c;
		}
		i--;
	}
	g = a;
	r = b;
	printf("a:%d, b:%d, c:%d, i:%d, g:%d, r:%d\n", a, b, c, i, g, r);
}

int main() {
	fun();
}

