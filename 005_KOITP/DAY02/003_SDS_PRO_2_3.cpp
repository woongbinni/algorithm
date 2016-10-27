/********************************************************************************
## 문제

동현이는 카이스트 대표 체스 선수이다. 기존의 체스 게임이 너무 쉬운 나머지 새로운 체스 말을 만들려고 한다. 이 말을 new night라고 정의하자.
이 말은 자신의 위치에서 왼쪽, 오른쪽, 왼쪽 대각선 위, 오른쪽 대각선 위 이렇게 총 네 가지 위치로 갈 수 있다.
N*M 격자로 이루어진 맵과 장애물 (말을 놓을 수 없는 위치) 가 주어졌을 때, newnight을 최대로 많이 두고 싶어한다.
동현이는 최근에 술을 너무 많이 마셔 문제를 풀 수 없는 상태이다. 우리가 취한 동현이를 도와주자.
위 그림처럼 newnight는 자신의 위치에서 A,D,E,C를 갈 수 있다. “한 번의 이동” 으로 닿을 수 없게 newnight를 최대로 많이 두고 싶다.

## 입력

입력의 첫 줄에는 테스트케이스의 개수 C가 주어진다. 각각의 테스트 케이스는 아래와 같이 두 부분으로 이루어진다. (1<= C <= 1000)
첫 번째 부분에서는 맵의 세로길이 N과 가로길이 M이 한 줄에 주어진다. (1 ≤ M ≤ 10, 1 ≤ N ≤ 10)
두 번째 부분에서는 정확하게 N줄이 주어진다. 그리고 각 줄은 M개의 문자로 이루어져있다. 모든 문자는 ‘.’(놓을 수 있는 자리) 또는 ‘x’(놓을 수 없는 자리, 소문자)로 구성된다.

## 출력
각각의 테스트 케이스에 대해 맵에서 둘 수 있는 최대 newnight의 수를 출력한다.

## 입력 예제

4
2 3
...
...
2 3
x.x
xxx
2 3
x.x
x.x
10 10
....x.....
..........
..........
..x.......
..........
x...x.x...
.........x
...x......
........x.
.x...x....

## 출력 예제

4
1
2
46

## 힌트
bitmask dp
D[i][j] = i에 j 상태로 놓을때 최대 knight 수
D[i][j] = max(D[i-1][k] + S[j])
S[j] = j에 들어있는 비트수

********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

char board[11][11];
int dp[11][1 << 11];
int visited[11] = { 0, };
int N, M;

int check(int current, int previous) {
	for (int i = 1; i < (1 << M); i <<= 1) {
		if ((current & i)) {
			if ((previous & (i * 2)) || (previous & (i / 2)))
				return false;
		}
	}
	return true;
}

int main(void) {
	int C;
	char str[11];
	scanf("%d", &C);

	for (int i = 0; i < C; ++i) {
		scanf("%d%d", &N, &M);
		for (int j = 1; j <= N; ++j) {
			scanf("%s", str);
			for (int k = 0; k < M; ++k) {
				board[j][k] = str[k];
			}
		}

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < (1 << M); j++) {
				int mmax = 0, bit = 0;
				bool isPossible = true;
				int idx = M - 1;
				for (int k = 1; k < (1 << M); k <<= 1) {
					if ((j & k) && board[i][idx] == '.') bit++;
					if (j & k && j & (k << 1)) {
						isPossible = false;
						break;
					}
					idx--;
				}
				if (!isPossible) continue;
				int a = 0;
				for (int k = 0; k < (1 << M); k++) {
					if (check(j, k)) {
						if (mmax < dp[i - 1][k]) {
							mmax = max(dp[i - 1][k], mmax);
							a = k;
						}

					}
				}
				dp[i][j] = mmax + bit;
				ans = max(ans, dp[i][j]);
			}
		}
		printf("%d\n", ans);

	}

	return 0;
}