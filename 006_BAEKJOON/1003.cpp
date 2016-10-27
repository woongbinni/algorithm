/********************************************************************************
https://www.acmicpc.net/problem/1003
********************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int T, N;
int ans_0, ans_1;

int fibonacci(int n) {
	if (n == 0) {
		ans_0 += 1;
		return 0;
	} else if (n == 1) {
		ans_1 += 1;
		return 1;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main(void) {
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		ans_0 = ans_1 = 0;

		scanf("%d", &N);

		fibonacci(N);

		printf("%d %d\n", ans_0, ans_1);
	}

	return 0;
}