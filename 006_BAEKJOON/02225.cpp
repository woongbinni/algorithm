/*
## 문제
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.
덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.

## 입력
첫 번째 줄에 두 정수 N, K가 공백으로 분리되어 주어진다. (1 ≤ N, K ≤ 200)

## 출력
첫 번째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.

## 예제 입력
20 2

## 예제 출력
21

D[i][j] = 0~N까지의 숫자를 i개 이용해서 j를 만드는 경우의 수
D[0][0] = 1;
D[i][j] = sum(D[i-1][k])(0 <= k <= j)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, K;
unsigned long long cache[201][201];

unsigned long long solve(int N, int K) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			cache[i][j] = 0;
			for (int k = 1; k <= j; ++k) {
				cache[i][j] += cache[i - 1][k];
			}
			cache[i][j] %= 1000000000;
		}
	}
	return cache[N][K];
}

int main(void) {
	memset(cache, 0x00, sizeof(cache));
	for (int i = 0; i < 201; ++i) {
		cache[0][i] = 1;
	}

	scanf("%d%d", &N, &K);

	printf("%llu\n", solve(N, K) % 1000000000);

	return 0;
}