#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count[8003];
int count_max[2];
int in[500001];
int max = -4000;
int min = 4000;
int max_dup = 0;
long long sum=0;

int cmp(const void *a, const void *b){
    return *(int*)a < *(int*)b;
}

int main() {
    int N;
    memset(count, 0x00, sizeof(count));
    scanf("%d", &N);

    for(int i=0; i<N; ++i){
        scanf("%d", &(in[i]));
        count[in[i]+4000]++;
        if(count[in[i]+4000] > max_dup){
            max_dup = count[in[i]+4000];
        }
        sum += in[i];
        if(in[i] > max){
            max = in[i];
        }
        if(in[i] < min){
            min = in[i];
        }
    }
    qsort(in, N, sizeof(int), cmp);

    printf("%0.f\n", (double)sum/N);
    printf("%d\n", in[N/2]);
    int dup = 0;
    for(int i=0; i<=8001; ++i){
        if(dup == 2)
            break;
        if(count[i] == max_dup){
            count_max[dup] = i - 4000;
            dup++;
        }
    }
    printf("%d\n", count_max[dup-1]);
    printf("%d\n", max - min);

    return 0;
}