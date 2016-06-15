#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
int num[101];
int sum[101];
int result = 0;
int temp;

int cmp(const void * a, const void * b)
{
    return ( *(int*)a - * (int*)b );
}

int main(void) {
    int testcase;

    scanf("%d", &testcase);

    while (testcase--) {
        result = 0;

        scanf("%d", &N);

        for (int i = 0; i < N; ++i) {
            scanf("%d", &(num[i]));
        }

        qsort(num, N, sizeof(int), cmp);

        for (int i = 1; i < N; --N) {
            temp = 0;
            for (int j = 0; j <= 1; ++j) {
                temp += num[j];
            }
            sum[0] = temp;
            result += temp;
            for (int j = 2; j < N; ++j) {
                sum[j - 1] = num[j];
            }
            qsort(sum, N - 1, sizeof(int), cmp);
            for (int j = 0; j < N - 1; ++j) {
                num[j] = sum[j];
            }
        }

        printf("%d\n", result);

    }
    return 0;
}