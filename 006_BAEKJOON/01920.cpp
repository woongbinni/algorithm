#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
int ns[1000001];

int cmp(const void * a, const void * b)
{
    return ( *(int*)a > *(int*)b );
}

int binarySearch(int target, int startIdx, int endIdx){
    if(startIdx > endIdx){
        return 0;
    }
    int mid = (startIdx + endIdx) / 2;
    if(ns[mid] == target){
        return 1;
    }
    else if(ns[mid] > target){
        return binarySearch(target, startIdx, mid-1);
    }
    else{
        return binarySearch(target, mid+1, endIdx);
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        scanf("%d", &(ns[i]));
    }

    qsort(ns, N, sizeof(int), cmp);

    scanf("%d", &M);
    for(int i=0; i<M; ++i){
        int in;
        scanf("%d", &in);
        printf("%d\n", binarySearch(in, 0, N-1));
    }

    return 0;

}