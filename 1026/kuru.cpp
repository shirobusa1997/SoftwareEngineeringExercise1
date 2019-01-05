#include <iostream>
#include <stdio.h>

int fib_s(int n, int *count) {
	
	if (n == 0 || n == 1) {
		return 1;
	}
	(*count)++;
	return fib_s(n - 1, count) + fib_s(n - 2, count);

}

int fib_l(int n, int *count) {
	int j,F=1,f1=0,f2=0;
	for (j = 0; j <= n; j++) {
		if (n == 0 || n == 1) {
			return 1;
		}
		else {
			if (j != 0) {
				(*count)++;
				f2 = f1;
				f1 = F;
				F += f2;
			}
			
		}
	}
	return F;

}
int main()
{
	int n, count1 = 0, count2 = 0;

	printf("フィ,ボナッチ数の何番目を求めるか記入してください");
	scanf("%d", &n);
	printf("再帰の場合の結果%d %d\n", fib_s(n,&count1), count1);
	printf("ループの場合の結果%d %d\n", fib_l(n,&count2), count2);


	return(0);
}