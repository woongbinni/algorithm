/********************************************************************************
## 문제
큰 방에 N개의 풍선이 떠있다. 풍선들은 왼쪽부터 오른쪽까지 일렬로 있다. 진솔이는 화살 가지고 노는 것과 사냥 연습하는 것을 좋아한다. 진솔이는 화살을 왼쪽에서 오른쪽으로 쏜다.
높이는 임의로 선택한다. 화살은 선택된 높이 H에서 풍선을 마주칠 때까지 왼쪽에서 오른쪽으로 이동한다. 화살이 풍선을 마주치는 순간, 풍선은 터지고 사라진다.
화살은 계속해서 가던길을 가는데 높이는 1 줄어든다. 그러므로 만약 화살이 높이 H에서 이동 중이었다면 풍선을 터트린 후에는 높이가 H-1이 된다.
우리의 목표는 모든 풍선을 터트리되 가능한한 적은 화살을 사용하는 것이다.

## 입력
첫 번째 줄에는 정수 N(1 ≤ N ≤ 1 000 000)이 들어온다.
두 번째 줄에는 배열 Hi가 N개 들어온다.
각각의 Hi(1 ≤ Hi ≤ 1 000 000)는 i번째 풍선의 높이에 해당하며 왼쪽에서 오른쪽으로 나열되는 순서이다.

## 출력
첫번째 줄 한줄에 최소한 필요한 화살의 갯수를 출력한다.

## 예제 입력 1

5
2 1 5 4 3

## 예제 출력 1

2

## 예제 입력 2

5
1 2 3 4 5

## 예제 출력 2

5

## 예제 입력 3

5
4 5 2 1 4

## 예제 출력 3

3
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int info[1000001];
int arrow_cnt[1000001];
int result = 0;
int N;

int main(void) {
    memset(arrow_cnt, 0x00, sizeof(arrow_cnt));
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &(info[i]));
    }

    arrow_cnt[info[1]] += 1;
    for (int i = 1; i <= N; ++i) {
        if (arrow_cnt[info[i]]) {
            arrow_cnt[info[i]] -= 1;
            arrow_cnt[info[i] - 1] += 1;
        }
        else {
            arrow_cnt[info[i] - 1] += 1;
        }
    }

    for (int i = 0; i <= N; ++i) {
        result += arrow_cnt[i];
    }

    printf("%d\n", result);

    return 0;
}