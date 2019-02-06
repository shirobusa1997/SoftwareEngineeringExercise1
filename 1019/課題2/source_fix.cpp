#include <iostream>
#include <stdio.h>

int function(int x, int y){
	int min = x - y, m = 1;

	for (int count = x; count > min; count--){ m *= count; }

	return m;
}

int main(void){
	int a, b, r = -1;

	scanf("%d %d", &a, &b);

	r = (a >= b && b > 0) ? r = function(a, b) : r ;

	printf("Result>>>\nr	: %d\n", r);

	return 0;

}