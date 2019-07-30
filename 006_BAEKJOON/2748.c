#include <stdio.h>

unsigned long long fibo[92];

int main(void){
    int N;

    fibo[0] = 0;
    fibo[1] = 1;

    for(int i=2; i<=90; ++i){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    scanf("%d", &N);
    printf("%llu\n", fibo[N]);

    return 0;
}

