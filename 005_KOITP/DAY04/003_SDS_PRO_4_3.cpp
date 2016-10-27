/********************************************************************************
## 문제
강희는 악마의 바다에 어마어마한 보물이 숨겨져 있는 보물섬이 있다는 정보를 입수했다.
하지만 악마의 바다에는 해류가 매우 복잡하게 흐르고 있기 때문에 강희는 좀처럼 보물을 얻고 돌아올 길을 찾기가 힘들어 여러분에게 도움을 요청했다.
강희가 악마의 바다에서 보물을 찾아올 수 있는 최단 시간을 계산하자.
악마의 바다에는 1번부터 N번까지 섬이 N개가 있으며, 서로 다른 섬들을 연결하는 해류가 M개 존재한다.
해류는 한 방향으로만 흐르며 어떤 두 쌍을 잇는 해류가 여러개 존재할 수도 있다. 강희는 현재 1번 섬에 있으며, 보물섬에 들렀다가 다시 1번 섬으로 돌아와 악마의 바다를 탈출하려고 한다.

## 입력
첫 번째 줄에 줄에는 섬의 개수 N과 섬들을 잇는 해류의 개수 M이 공백으로 분리되어 주어진다. (2 ≤ N ≤ 3,000, 1 ≤ M ≤ 20,000)
두 번째 줄에는 보물섬의 번호 T가 주어진다. (2 ≤ T ≤ N)
세 번째 줄부터 M개의 줄에 걸쳐 각 줄마다 해류의 정보를 나타내는 세 자연수 Xi, Yi, Zi가 주어진다. Xi는 해류의 시작섬 번호, Yi는 해류의 도착섬 번호,
Zi는해류를 타고 섬과 섬을 이동하는데 걸리는 시간을 나타낸다. (1 ≤ Xi, Yi ≤ N, 1 ≤ Zi ≤ 1,000)

## 출력
첫 번째 줄에 강희가 1번 섬에서 출발해 보물을 찾아 다시 1번 섬으로 돌아올 수 있는지 여부를 첫 줄에 출력한다. 돌아올 수 있는 경우 YES, 아닌 경우 NO를 출력한다.
만약, 첫 번째 줄에 YES를 출력한 경우에는 두 번째 줄에 보물을 찾아 악마의 바다를 탈출하는데 드는 최단 시간을 출력한다.

## 예제 입력

3 4
3
1 2 4
2 3 3
3 2 2
3 1 1

## 예제 출력

YES
8

********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <vector>
using namespace std;

typedef struct _wave {
	int start;
	int end;
	int cost;
} wave;

typedef struct _island {
	vector<wave> wave_info;
} island;

island island_info[3001];
list<wave> bfs_queue;
unsigned int go_cost[3001];
bool visited[3001];
unsigned int back_cost[3001];
int N, M, T;


int main(void) {
	memset(go_cost, 0xFF, sizeof(go_cost));
	memset(back_cost, 0xFF, sizeof(back_cost));

	scanf("%d%d", &N, &M);
	scanf("%d", &T);

	for (int i = 0; i < M; ++i) {
		wave temp;
		scanf("%d%d%d", &(temp.start), &(temp.end), &(temp.cost));
		island_info[temp.start].wave_info.push_back(temp);
	}

	memset(visited, false, sizeof(visited));
	visited[1] = true;
	go_cost[1] = 0;
	for (int i = 0; i < island_info[1].wave_info.size(); ++i) {
		bfs_queue.push_back(island_info[1].wave_info[i]);
	}

	while (bfs_queue.size() > 0) {
		wave pop = bfs_queue.front();
		bfs_queue.pop_front();

		if ((visited[pop.start] == true) && (go_cost[pop.end] > go_cost[pop.start] + pop.cost)) {
			go_cost[pop.end] = go_cost[pop.start] + pop.cost;
			visited[pop.end] = true;
		}
		else {
			continue;
		}

		if (pop.end == T) {
			continue;
		}

		for (int i = 0; i < island_info[pop.end].wave_info.size(); ++i) {
			bfs_queue.push_back(island_info[pop.end].wave_info[i]);
		}
	}

	memset(visited, false, sizeof(visited));
	visited[T] = true;
	back_cost[T] = 0;
	for (int i = 0; i < island_info[T].wave_info.size(); ++i) {
		bfs_queue.push_back(island_info[T].wave_info[i]);
	}

	while (bfs_queue.size() > 0) {
		wave pop = bfs_queue.front();
		bfs_queue.pop_front();

		if ((visited[pop.start] == true) && (back_cost[pop.end] > back_cost[pop.start] + pop.cost)) {
			back_cost[pop.end] = back_cost[pop.start] + pop.cost;
			visited[pop.end] = true;
		}
		else {
			continue;
		}

		if (pop.end == 1) {
			continue;
		}

		for (int i = 0; i < island_info[pop.end].wave_info.size(); ++i) {
			bfs_queue.push_back(island_info[pop.end].wave_info[i]);
		}
	}

	if (go_cost[T] == 0xFFFFFFFF || back_cost[1] == 0xFFFFFFFF) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		printf("%d\n", go_cost[T] + back_cost[1]);
	}


	return 0;
}