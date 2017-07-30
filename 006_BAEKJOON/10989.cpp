#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int N;
long long arr[10001];

int main(void){
    memset(arr, 0x00, sizeof(arr));
    scanf("%d", &N);

    for(long long i=0; i<N; ++i){
        int temp;
        scanf("%d", &temp);
        arr[temp] += 1;
    }

    for(int i=0; i<=10000; ++i){
        for(long long j=0; j<arr[i]; ++j){
            printf("%d\n", i);
        }
    }

    return 0;    
}