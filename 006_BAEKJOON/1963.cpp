/*
## 문제
형석이는 다음날 SDS에 강의를 하러 간다. 하지만 아침에 일찍 일어나야 한다는 부담감에 고급 알람 시계를 준비하였다. 최근에 화장실 사진찍기, 뺨 때리기, 냄새 뿌리기 등의 알람 시계가 나오고 있지만, 형석이는 강의를 위해 머리를 써야 끌 수 있는 알람을 준비하였다.
이 시계의 시간을 맞춰 놓고, 그 시간이 되어 울리기 시작하면, 4자리의 소수 2개가 고급 알람 시계에 표시된다. 첫 번째 적혀 있는 수는 숫자를 변경할 수 있게 되어있다. 그럼 이제 알람을 끄는 방법은 간단하다. 첫 번째 적혀 있는 소수를 두 번째 적혀 있는 소수로 변경하면 된다. 이때, 한번에 한자리만 변경할 수 있고, 한자리를 변경하였을 때, 변경된 수는 소수이어야 한다. 또한 4자리 소수이기 때문에, 경로 중간에도 4자리를 유지해야한다. (즉, 1000이상의 소수) 형석이는 알람이 계속 울리는 것이 싫기 때문에, 최대한 빠르게 알람을 끄고 싶어한다. 형석이를 도와 어떻게 하면 최소한의 단계로 첫 번째 소수를 두 번째 소수로 변경할 수 있는지 구하시오.
예를 들어서 1033이라는 수를 8179로 변경한다면, 1033 1733 3733 3739 3779 8779 8179의 순서로 변경이 가능하다.

## 입력
첫 번째 줄에 테스트 케이스의 수 T가 주어진다.
각 테스트 케이스의 첫 번째 줄에 고급 알람 시계에 적혀 있는 두 개의 소수가 공백으로 분리되어 주어진다. (1,000 ≤ 소수 ≤ 9,999)

## 출력
각 테스트 케이스마다 첫 번째 줄에 첫 번째 소수를 두 번째 소수로 변경하는 최소한의 단계수를 출력한다.

## 예제 입력

3
1033 8179
1373 8017
1033 1033

예제 출력

6
7
0
*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>

bool isPrime[10001];
int min_cost[10001];
int result = 0;

typedef struct _pair {
	int a;
	int b;
} pairs;

pairs make_pair(int a, int b) {
	pairs temp;
	temp.a = a;
	temp.b = b;
	return temp;
}

void check_prime(void) {
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i < 10000; ++i) {
		if (isPrime[i] == false)
			continue;
		for (int j = i + i; j < 10000; j += i) {
			isPrime[j] = false;
		}
	}
}

int main(void) {
	int T;
	int from, to;
	check_prime();

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int from, to;
		int result = -1;
		int visit[10001] = {};
		queue<pairs> que;        
		scanf("%d %d", &from, &to);

		que.push(make_pair(from, 0));
		visit[from] = 1;
		//pair<int, int> a;
		while (!que.empty()) {
			pairs temp = que.front();

			int Digit[4];
			int tempNum = temp.a;
			int d[4] = { 1000, 100, 10, 1 };

			if (temp.a == to) {
				result = temp.b;
				break;
			}

			for (int i = 0; i < 4; i++) {
				Digit[i] = tempNum / d[i];
				tempNum = tempNum % d[i];
			}

			que.pop();

			for (int i = 0; i < 4; i++) {
				tempNum = temp.a - Digit[i] * d[i];
				for (int j = 0; j <= 9; j++)
				{
					int compareNum = tempNum + d[i] * j;
					if (i == 0 && j == 0)
						continue;

					if (isPrime[compareNum] == true && visit[compareNum] == 0) {
						visit[compareNum] = 1;
						que.push(make_pair(compareNum, temp.b + 1));
					}

				}
			}

		}
		printf("%d\n", result);
	}
}