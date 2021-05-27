#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;

#define SIZE 2000+1

int N;
int a[SIZE];
long long dp[SIZE][SIZE];

static int right(int num) {
	return (num + 1) % N;
}

static int left(int num) {
	return (num + N - 1) % N;
}

long long ioi(int, int);
long long joi(int, int);

long long ioi(int l, int r) {
	if (right(r) == l) return 0;
	if (a[left(l)] > a[right(r)]) return joi(left(l), r);

	return joi(l, right(r));
}

long long joi(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (right(r) == l) return dp[l][r] = 0;

	long long t1 = a[left(l)] + ioi(left(l), r);
	long long t2 = a[right(r)] + ioi(l, right(r));
	return dp[l][r] = max(t1, t2);
}

int main() {
    scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &(a[i]));
	}
	memset(dp, -1, sizeof(dp));

	long long answer = 0;
	for (int i = 0; i < N; i++) {
		long long result = a[i] + ioi(i, i);
		answer = max(result, answer);
	}

	printf("%lld\n", answer);
	return 0;
}