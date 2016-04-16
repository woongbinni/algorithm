#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int people[101][51];
int row01[51];
int row02[51];
int mid[51];

void Valid(int len){
    int temp;
    for(int i=0; i<len; ++i){
        temp = max(row01[i], row02[i]);
        printf("%d ", min(temp, mid[i]));
    } 
}

int main(void) {
    int test_case;
    int N;

    scanf("%d", &test_case);

    for (int idx = 1; idx <= test_case; ++idx) {
        memset(people, 0x00, sizeof(people));
        scanf("%d", &N);
        int len = 2 * N - 1;

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &(people[i][j]));

                if(i == N-2){
                    row01[j] = people[i][j] +1;
                }
                if(i == N-1){
                    mid[j] = people[i][j];
                }
                if(i == N){
                    row02[j] = people[i][j] +1;
                }
            }
        }

        printf("Case #%d: ", idx);
        Valid(N);
        printf("\n");
    }


    return 0;
}