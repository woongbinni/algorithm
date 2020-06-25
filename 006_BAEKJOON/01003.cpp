/********************************************************************************
https://www.acmicpc.net/problem/1003
********************************************************************************/

#include <stdio.h>

typedef struct _fibo_cnt {
    unsigned int cnt0;
    unsigned int cnt1;
}fibo_cnt;

fibo_cnt fibo_cnts[42];

int main(void){
    int N;

    fibo_cnts[0].cnt0 = 1;
    fibo_cnts[0].cnt1 = 0;

    fibo_cnts[1].cnt0 = 0;
    fibo_cnts[1].cnt1 = 1;

    for(int i=2; i<=40; ++i){
        fibo_cnts[i].cnt0 = fibo_cnts[i-1].cnt0 + fibo_cnts[i-2].cnt0;
        fibo_cnts[i].cnt1 = fibo_cnts[i-1].cnt1 + fibo_cnts[i-2].cnt1;

    }

    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        int temp;
        scanf("%d", &temp);

        printf("%u %u\n", fibo_cnts[temp].cnt0, fibo_cnts[temp].cnt1);
    }

    return 0;
}
