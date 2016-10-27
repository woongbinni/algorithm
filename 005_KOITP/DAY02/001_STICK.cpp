/*
## 문제
N가지 종류의 서로 다른 길이의 막대기들이 있다. 이 막대기들을 적당히 사용해서, 총 길이가 K가 되도록 하고 싶다. 그 경우의 수를 구하시오. (각각의 막대기는 여러 번 사용할 수 있다.)

## 입력
첫 번째 줄에 N, K가 공백으로 분리되어 주어진다. (1 ≤ N ≤ 100, 1 ≤ K ≤ 10,000)
두 번째 줄부터 N개의 줄에 걸쳐 각 막대기의 길이가 주어진다. 각 막대기의 길이는 1 이상 1,000 하이다.

## 출력
첫 번째 줄에 막대기를 이용해 총 길이 K를 만들 수 있는 경우의 수를 1,000,000으로 나눈 나머지를 출력한다.

## 예제 입력
3 10
1
2
5

## 예제 출력
10

D[i][j] = 1~i 막대기를 사용해서 j 길이를 만드는 경우의 수
D[0][0] = 1
D[i][j] = D[i-1][j] + D[i][j-L[i]]

보통 DP 문제를 보았을때... 
1). 문제를 그대로 줄인다.
    Fn = Fn-1 + Fn-2
2). 줄였는데 잘 안되면... knapsack algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cache[10001][101];
int stick[101];
int N, K;

int solve(int remain_K, int stick_idx) {
	if (remain_K == 0) {
		return 1;
	}
	if (cache[remain_K][stick_idx] != -1) {
		return cache[remain_K][stick_idx];
	}
	cache[remain_K][stick_idx] = 0;

	for (int i = stick_idx; i <= N; ++i) {
		if (remain_K - stick[i] < 0) continue;
		cache[remain_K][stick_idx] += solve(remain_K - stick[i], i);
		cache[remain_K][stick_idx] %= 1000000;
	}
	return cache[remain_K][stick_idx];
}

int main(void) {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &N, &K);

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &(stick[i]));
	}

	printf("%d\n", solve(K, 1) % 1000000);

	return 0;
}
