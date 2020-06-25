/*
## 문제
벌레 한 마리가 동굴을 지나려고 한다. 모두가 알다시피 동굴은 석순과 종유석이 굉장히 많은 공간이다. 이 벌레는 이렇게 장애물이 많은 동굴을 지나갈 것이다. 동굴의 길이는 N미터이고, 높이는 H미터이다. N은 항상 짝수이고, 장애물은 석순과 종유석이 번갈아 가면서 등장하고, 첫 장애물을 항상 석순이다.
아래 예제는 N=14, H =5의 예이다.
남자다운 이 벌레는 장애물을 굳이 피하지 않는다. 즉, 처음 정한 높이에서 일직선으로 장애물을 부수면서 지나간다. 벌레가 아래에서 4번째 구간으로 지나가면, 아래 그림과 같이 8개의 장애물을 부수게 된다.
하지만, 첫 번째나 다섯 번째 구간으로 날아간다면 벌레는 7개의 장애물만 부시면 된다.
벌레는 아픔을 느끼는 남자이기 때문에, 최소한의 장애물만 부시고 싶어한다. 여러분은 이 벌레가 최소 몇 개의 장애물만 부수고도 통과할 수 있는지 구하고, 그러한 구간이 총 몇 개 있는지 구하는 프로그램을 작성하시오.

## 입력
첫 번째 줄에 N과 H가 주어진다. N은 항상 짝수이다. (2 ≤ N ≤ 200,000, 2 ≤ H ≤ 500,000)

## 두 번째 줄부터 N개의 줄에 걸쳐 장애물의 크기가 순서대로 주어진다. 장애물의 크기는 H보다 작은 양수이다.

## 출력
첫 번째 줄에 개똥벌레가 파괴해야 하는 장애물의 최소값과 그러한 구간의 수를 공백으로 구분하여 출력하시오.

## 예제 입력
14 5
1
3
4
2
2
4
3
4
3
3
3
2
3
3

## 예제 출력
7 2

*/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos_wall[500001];
int stone_up[100001];
int stone_down[100001];

int cmp(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}

int main(void) {
    int N, H, half_N;
    int T;
    int i, j, k;
    memset(pos_wall, 0x00, sizeof(pos_wall));

    scanf("%d%d", &N, &H);
    half_N = N / 2;

    j = k = 0;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &T);
        if (i % 2 == 1) {
            stone_up[j] = T;
            j++;
        }
        else {
            stone_down[k] = T;
            k++;
        }
    }

    qsort(stone_up, N / 2, sizeof(int), cmp);
    //for (i = 0; i < half_N; ++i) {
    //  printf("%d ", stone_up[i]);
    //}
    //printf("\n");

    qsort(stone_down, N / 2, sizeof(int), cmp);
    //for (i = 0; i < half_N; ++i) {
    //  printf("%d ", stone_down[i]);
    //}
    //printf("\n");

    i = stone_up[half_N - 1];
    j = half_N - 1;
    int stacked = 0;

    while (i > 0) {
        if (i <= stone_up[j]) {
            int same_cnt = 1;
            while (stone_up[j] == stone_up[j - same_cnt]) {
                same_cnt++;
            }
            while (i > stone_up[j - same_cnt]) {
                pos_wall[i] += (stacked + same_cnt);

                //for (k = 1; k <= H; ++k) {
                //  printf("%d ", pos_wall[k]);
                //}
                //printf("\n");

                i--;
            }
            stacked += same_cnt;
            j -= same_cnt;
        }
    }

    i = H - stone_down[half_N - 1] + 1;
    j = half_N - 1;
    stacked = 0;

    while (i <= H) {
        if (i > H - stone_down[j]) {
            int same_cnt = 1;
            while (stone_down[j] == stone_down[j - same_cnt]) {
                same_cnt++;
            }
            while (i <= H - stone_down[j - same_cnt]) {
                pos_wall[i] += (stacked + same_cnt);

                //for (k = 1; k <= H; ++k) {
                //  printf("%d ", pos_wall[k]);
                //}
                //printf("\n");

                i++;
            }
            stacked += same_cnt;
            j -= same_cnt;
        }
    }

    qsort(&(pos_wall[1]), H, sizeof(int), cmp);

    //for (i = 1; i <= H; ++i) {
    //  printf("%d ", pos_wall[i]);
    //}
    //printf("\n");

    int result_cnt = 1;

    while (pos_wall[1] == pos_wall[1 + result_cnt]) {
        result_cnt++;
    }


    printf("%d %d\n", pos_wall[1], result_cnt);
}