/********************************************************************************
## 문제
N개의 정수가 주어진다. 이 중 가장 많이 등장하는 수를 구하시오. 만약 이런 수가 여러 개라면 작은 수를 출력하세요.
시간제한: 1초

## 입력
첫째 줄에는 정수의 개수 N이 주어진다. (1<=N<=1000000)
둘째 줄부터 N개 줄에 정수가 주어진다. 이 수의 절대값은 2^31 - 1 이하이다.

## 출력
가장 많이 등장하는 정수를 출력하시오.

## 입력 예제
4
1
2
3
3

## 출력 예제
3

## merge sort를 확실히 알아두는 것이 좋다.
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void *b) {
	return (*(int*)a) - (*(int*)b);
}

int arr[1000001];
int N;

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &(arr[i]));
	}

	qsort(arr, N, sizeof(int), cmp);

	int max_cnt = 0;
	int result = arr[0];
	int same_cnt = 1;
	int check_num = arr[0];

	for (int i = 1; i < N; ++i) {
		if (check_num == arr[i]) {
			same_cnt += 1;
		}
		else {
			if (same_cnt > max_cnt) {
				max_cnt = same_cnt;
				result = check_num;
			}
			same_cnt = 1;
			check_num = arr[i];
		}
	}
	if (same_cnt > max_cnt) {
		max_cnt = same_cnt;
		result = check_num;
	}

	printf("%d\n", result);
	return 0;
}