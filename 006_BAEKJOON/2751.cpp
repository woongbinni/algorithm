#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int N;
int arr[1000001];

bool comp(int a, int b){
    return a < b;
}

int main(void){
    scanf("%d", &N);

    for(int i=0; i<N; ++i){
        scanf("%d", &(arr[i]));
    }

    sort(arr, &(arr[N]), comp);

    for(int i=0; i<N; ++i){
        printf("%d\n", arr[i]);
    }

    return 0;    
}