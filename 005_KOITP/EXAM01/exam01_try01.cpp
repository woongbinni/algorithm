#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int cache[101][101][101][101];
int result[101];
int result_cnt;
int last_result;
int N, K;

bool cmp(int a, int b) {
	return a > b;
}

void calc_result(int pos_x, int pos_y, int len_x, int len_y) {
	int sum = 0;

	if (len_x == 1 && len_y == 1) {
		sum = cache[pos_x][pos_y][1][1];
	}
	else {
		sum = cache[pos_x-1][pos_y-1][len_x - 1][len_y - 1] + cache[pos_x][pos_y-1][1][len_y - 1] + cache[pos_x-1][pos_y][len_x - 1][1] + cache[pos_x][pos_y][1][1];
	}
	cache[pos_x][pos_y][len_x][len_y] = sum;

	if (sum >= last_result) {
		if (result_cnt >= N) {
			result[N - 1] = sum;
			sort(result, result + N, cmp);
			last_result = result[N - 1];
		}
		else {
			result[result_cnt++] = sum;
		}
	}
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		memset(cache, 0x00, sizeof(cache));
		last_result = 0;
		result_cnt = 0;
		scanf("%d%d", &N, &K);

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				scanf("%d", &(cache[i][j][1][1]));
			}
		}

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				for (int k = 1; k <= i; ++k) {
					for (int l = 1; l <= j; ++l) {
						calc_result(i, j, k, l);
					}
				}
			}
		}

		sort(result, result + N, cmp);
		printf("#%d %d\n", tc, result[K - 1]);
	}


}