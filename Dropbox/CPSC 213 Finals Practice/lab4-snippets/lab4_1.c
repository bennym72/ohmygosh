#include <stdlib.h>

int  i = 0;
int  s = 0;
int  j = 0;
int a[] = {2,3,-4,6,0,1,7,-5,5,4};

void main () {
	
	while ( j<10 ) {
		s += a[i];
		if (a[i] >= 0)
			i = a[i];
		else
			i = -a[i];
		j++;
	}
	
}
