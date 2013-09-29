#include <stdlib.h>
#include <stdio.h>

int res = 0;
int k = 10;

int fun(int passed_k){
	if (passed_k < 2) {
		return passed_k;
	}
	int temp_k = fun(passed_k - 1);
	int temp_k2 = fun(passed_k - 2);
	
	temp_k = temp_k << 1;
	int temp_k3 = temp_k2;
	temp_k2 = temp_k2 << 1;
	temp_k2 += (temp_k + temp_k3);
	printf("return: %d\n", temp_k2);
	return temp_k2;
}

void get() {
	res = fun(k/2);
	printf("res = %d\n", res);
}

void start() {
	get();
}

int main() {
	start();
	return 0;
}