#include <stdio.h>

int Fibo(int);

int main() {
    for(int i=0;i<=10;i++){
        printf("%d ",Fibo(i));
    }
}

int Fibo(int n) {
    if (n == 0 || n==1) {
        return 1;
    }
    return Fibo(n-1)+Fibo(n-2);
}