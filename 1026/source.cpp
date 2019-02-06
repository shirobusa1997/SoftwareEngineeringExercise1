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

int main(int argc, char **argv){
	int count_s = 0;
	int	count_l = 0;
	int ud;

	int ans_s, ans_l;

	scanf("%d", &ud);

	ans_s = fib_s(ud, &count_s);
	ans_l = fib_l(ud, &count_l);

	printf("RESULT >>>\nfib_s ANSWER    : %d\nfib_s EXPRCOUNT : %d\n", ans_s, count_s);
	printf("fib_l ANSWER    : %d\nfib_l EXPRCOUNT : %d\n", ans_l, count_l);

	return 0;
}