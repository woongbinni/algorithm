/********************************************************************************
## 문제
삼성 통신연구소는 레이저를 이용한 새로운 비밀 통신 시스템 개발을 위한 실험을 하고 있다. 실험을 위하여 일직선 위에 N개의 높이가 서로 다른 탑을 수평 직선의 왼쪽부터 오른쪽 방향으로 차례로 세우고,
각 탑의 꼭대기에 레이저 송신기를 설치하였다. 모든 탑의 레이저 송신기는 레이저 신호를 지표면과 평행하게 수평 직선의 왼쪽 방향으로 발사하고, 탑의 기둥 모두에는 레이저 신호를 수신하는 장치가 설치되어 있다.
하나의 탑에서 발사된 레이저 신호는 가장 먼저 만나는 단 하나의 탑에서만 수신이 가능하다.
예를 들어 높이가 6, 9, 5, 7, 4인 다섯 개의 탑이 수평 직선에 일렬로 서 있고, 모든 탑에서는 주어진 탑 순서의 반대 방향(왼쪽 방향)으로 동시에 레이저 신호를 발사한다고 하자.
그러면, 높이가 4인 다섯 번째 탑에서 발사한 레이저 신호는 높이가 7인 네 번째 탑이 수신을 하고, 높이가 7인 네 번째 탑의 신호는 높이가 9인 두 번째 탑이, 높이가 5인 세 번째 탑의 신호도
높이가 9인 두 번째 탑이 수신을 한다. 높이가 9인 두 번째 탑과 높이가 6인 첫 번째 탑이 보낸 레이저 신호는 어떤 탑에서도 수신을 하지 못한다.
탑들의 개수 N과 탑들의 높이가 주어질 때, 각 각의 탑에서 발사한 레이저 신호를 어느 탑에서 수신하는지를 알아내는 프로그램을 작성하라.

## 입력
첫 번째 줄에 탑의 수 N이 주어진다. (1 ≤ N ≤ 500,000)
두 번째 줄에 N개의 탑들의 높이가 직선상에 놓인 순서대로 하나의 빈칸을 사이에 두고 각각 주어진다. (1 ≤ 탑의 높이 ≤ 100,000,000)

출력
첫 번째 줄에 주어진 탑들의 순서대로 각각의 탑들에서 발사한 레이저 신호를 수신한 탑들의 번호를 하나의 빈칸을 사이에 두고 출력한다. 만약 레이저 신호를 수신하는 탑이 존재하지 않으면 0을 출력한다.

힌트
입력 예제

5
6 9 5 7 4
출력 예제

0 0 2 2 4
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <unistd.h>
using namespace std;

typedef struct _antenna {
	int idx;
	int value;
} antenna;

int N;
list<antenna> stack01;
list<antenna> stack02;
int result[500001];

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		antenna temp;
		temp.idx = i + 1;
		scanf("%d", &(temp.value));
		stack01.push_front(temp);
	}

	while (stack01.size() > 0) {
		antenna temp01 = stack01.front();

		stack01.pop_front();

		if (stack02.size() != 0) {
			antenna temp02 = stack02.front();

			while (temp02.value <= temp01.value) {
				result[temp02.idx] = temp01.idx;
				stack02.pop_front();
				if (stack02.size() > 0) {
					temp02 = stack02.front();
				}
				else {
					break;
				}
			}
			stack02.push_front(temp01);
		}
		else {
			stack02.push_front(temp01);
		}
		// sleep(1);
		// printf("stack 01 : %lu stack 02 : %lu\n", stack01.size(), stack02.size());
		// printf("01 ==> ");
		// for (list<antenna>::iterator it = stack01.begin(); it != stack01.end(); it++) {
		// 	printf("%d |", (*it).value);
		// }
		// printf("\n");
		// printf("02 ==> ");
		// for (list<antenna>::iterator it = stack02.begin(); it != stack02.end(); it++) {
		// 	printf("%d |", (*it).value);
		// }
		// printf("\n");
		// for (int i = 1; i <= N; ++i) {
		// 	printf("%d ", result[i]);
		// }
		// printf("\n");
	}


	while (stack02.size() > 0) {
		antenna temp02 = stack02.front();
		result[temp02.idx] = 0;
		stack02.pop_front();
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}