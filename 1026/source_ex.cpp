#include <iostream>
#include <stdio.h>

int fib_s(int n, int *count){
	if (n == 0 || n == 1){
		return 1;
	}
	(*count)++;
	return fib_s(n-1, count) + fib_s(n-2, count);
}

int fib_l(int n, int *count){
	int n1 = 0, n2 = 1, n3 = 1;
	for(int i = 0; i < n; i++){
		(*count)++;
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
	}

	return n3;
}

void exec(int n, int (*func)(int, int*)){
	int count = 0;
	printf("RESULT >>>\nfunc ANSWER    : %d\nfunc EXPRCOUNT : %d\n", (*func)(n, &count), count);
}

int main(int argc, char **argv){
	int ud;

	scanf("%d", &ud);

	if(ud < 0){
		printf("ERROR: nは0以上の整数でなければなりません。\n");
		return 1;
	} else {
		exec(ud, fib_s); exec(ud, fib_l);
	}

	return 0;
}