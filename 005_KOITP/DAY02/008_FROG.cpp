/********************************************************************************
문제
2차원 평면의 호수에 개구리 한 마리가 있다. 개구리는 호수위에 떠있는 연꽃들 사이를 돌아다니고 있다. 개구리는 총 4가지 방향으로 이동이 가능하다. 현재 위치인, (x, y)에서 임의의 양의 정수 d에 대하여,

A. (x+d, y+d)로 이동.
B. (x+d, y-d)로 이동.
C. (x-d, y+d)로 이동.
D. (x-d, y-d)로 이동.

가능하다.
개구리는 네 방향 중 한가지를 골라서, 그 방향에 있는 가장 가까운 연꽃으로 이동한다. 만약 연꽃이 없다면 제자리에 있는다. 그리고 개구리가 이동한 다음에, 원래 연꽃은 가라앉는다.
연꽃의 위치와, 개구리의 이동방향이 주어졌을 때, 개구리의 최종 위치를 출력하시오.

## 입력
첫 번째 줄에 연꽃의 수 N과 점프의 수 K가 공백으로 분리되어 주어진다. (1 ≤ N ≤ K ≤ 100,000)
두 번째 줄에는 개구리가 고른 방향 K개가 주어진다. 이 방향은 ‘A’, ‘B’, ‘C’, ‘D’로만 이루어져 있다.
세 번째 줄부터 N개의 줄에 걸쳐서 각 연꽃의 좌표 x, y가 주어진다. (0 ≤ x, y ≤ 1,000,000,000) 개구리는 입력에서 처음 주어지는 연꽃위에 있다.

## 출력
개구리의 점프가 끝났을 때, 개구리의 좌표를 출력한다.

힌트
예제 입력

7 5
ACDBB
5 6
8 9
4 13
1 10
7 4
10 9
3 7
예제 출력

7 4
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct _floatflower{
	int idx;
	int x;
	int y;
	int sum;
	int sub;
}floatflower;

bool sum_cmp(floatflower a, floatflower b){
	return a.sum < b.sum;
}

bool sub_cmp(floatflower a, floatflower b){
	return a.sub < b.sub;
}

int binary_search_of_sum(int mid_idx, int searchItem){

}

int N, K;
floatflower flowers[100001];
floatflower sum_sorted[100001];
floatflower sub_sorted[100001];
char step[100001];

int main(void){
	scanf("%d%d", &N, &K);
	scanf("%s", step);

	for(int i=0; i<N; ++i){
		scanf("%d %d", &(flowers[i].x), &(flowers[i].y));
		flowers[i].idx = i;
		flowers[i].sum = flowers[i].x + flowers[i].y;
		flowers[i].sub = flowers[i].x - flowers[i].y;
	}

	memcpy(sum_sorted, flowers, sizeof(flowers));
	sort(sum_sorted, sum_sorted+N, sum_cmp);

	for(int i=0; i<N; ++i){
		printf("%d|%d|%d|%d\n", sum_sorted[i].idx, sum_sorted[i].x, sum_sorted[i].y, sum_sorted[i].sum);
	}


	memcpy(sub_sorted, flowers, sizeof(flowers));
	sort(sub_sorted, sub_sorted+N, sub_cmp);

	for(int i=0; i<N; ++i){
		printf("%d|%d|%d|%d\n", sub_sorted[i].idx, sub_sorted[i].x, sub_sorted[i].y, sub_sorted[i].sub);
	}






	return 0;
}