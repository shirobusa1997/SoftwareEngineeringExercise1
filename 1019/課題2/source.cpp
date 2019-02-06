#include <iostream>
#include <stdio.h>

int function(int x){
	int m = 1, n = 2;

	while(n <= x){
		m = m * n;
		n++;
	}

	return m;
}

int main(void){
	int a, b, r = -1;

	scanf("%d %d", &a, &b);

	r = (a >= b && b > 0) ? r = function(a)/function(a-b) : r ;

	printf("Result>>>\nr	: %d\n", r);

	return 0;

}