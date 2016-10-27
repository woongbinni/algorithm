/********************************************************************************
## 문제

N 개 농장의 (편의상 1 ,2 .. , N) 의 대표 암소 한 마리가, X ( 1 <= X <= N) 농장에서 열리는 파티에 참석하려고 한다. 
농장들은 단방향의 길들로 연결되어 있으며, 각 길마다 걸어가는데 걸리는 시간이 주어진다.
모든 소들은 파티에 걸어가야 하고 파티가 마친 후에는 자기가 속한 농장으로 돌아와야 한다. 모든 소들은 게을러서 가장 최단시간으로 올수 있는 최적의 길을 선택하려고 한다.
모든 소 들 중에서 농장으로 갔다가 돌아오는 데 가장 많이 걸리는 소의 시간은 얼마인가?

시간제한 : 0.5 초

## 입력

첫 번째 줄 : 정수 N , M , X 가 주어진다. (1<=N<=1000)는 농장의 수, (1<=M<=N*(N-1))은 도로의 갯수, (1<=X<=N)는 파티가 열리는 농장이다.
두 번재 줄에서 M+1 번째 줄 : i+1 번째 줄은 세 정수 Ai,Bi,Ci 가 주어진다. Ai 에서 Bi 로 가는데 Ti 시간이 소요된다는 것이다.

## 출력
파티에 참석했다 돌아오는 소 들 중 가장 긴 시간을 출력한다.

## 입력 예제
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

## 출력 예제
10

## 설명

4 -> 2 ( 3 )
2 -> 1 -> 3 -> 4 (7)
총 거리합은 10이고, 이 때가 가장 긴 경우이다.

********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _road {
	int start;
	int end;
	int cost;
} road;

typedef struct _farm {
	vector<road> road_info;
} farm;

farm farm_info[1001];
farm reverse_farm_info[1001];
list<road> bfs_queue;
unsigned int go_cost[1001];
unsigned int back_cost[1001];
unsigned int sum[1001];
bool visited[3001];
int N, M, X;


int main(void) {
	memset(go_cost, 0xFF, sizeof(go_cost));
	memset(back_cost, 0xFF, sizeof(back_cost));

	scanf("%d%d%d", &N, &M, &X);

	for (int i = 0; i < M; ++i) {
		road temp, reverse_temp;
		scanf("%d%d%d", &(temp.start), &(temp.end), &(temp.cost));
		reverse_temp.start = temp.end;
		reverse_temp.end = temp.start;
		reverse_temp.cost = temp.cost;
		farm_info[temp.start].road_info.push_back(temp);
		reverse_farm_info[reverse_temp.start].road_info.push_back(reverse_temp);
	}

	memset(visited, false, sizeof(visited));
	visited[X] = true;
	back_cost[X] = 0;
	for (int i = 0; i < farm_info[X].road_info.size(); ++i) {
		bfs_queue.push_back(farm_info[X].road_info[i]);
	}

	while (bfs_queue.size() > 0) {
		road pop = bfs_queue.front();
		bfs_queue.pop_front();

		if ((visited[pop.start] == true) && (back_cost[pop.end] > back_cost[pop.start] + pop.cost)) {
			back_cost[pop.end] = back_cost[pop.start] + pop.cost;
			visited[pop.end] = true;
		}
		else{
			continue;
		}

		for (int i = 0; i < farm_info[pop.end].road_info.size(); ++i) {
			bfs_queue.push_back(farm_info[pop.end].road_info[i]);
		}
	}

	memset(visited, false, sizeof(visited));
	visited[X] = true;
	go_cost[X] = 0;
	for (int i = 0; i < reverse_farm_info[X].road_info.size(); ++i) {
		bfs_queue.push_back(reverse_farm_info[X].road_info[i]);
	}

	while (bfs_queue.size() > 0) {
		road pop = bfs_queue.front();
		bfs_queue.pop_front();

		if ((visited[pop.start] == true) && (go_cost[pop.end] > go_cost[pop.start] + pop.cost)) {
			go_cost[pop.end] = go_cost[pop.start] + pop.cost;
			visited[pop.end] = true;
		}
		else{
			continue;
		}

		for (int i = 0; i < reverse_farm_info[pop.end].road_info.size(); ++i) {
			bfs_queue.push_back(reverse_farm_info[pop.end].road_info[i]);
		}
	}

	for(int i=1; i<=N; ++i){
		sum[i] = go_cost[i] + back_cost[i];
	}

	sort(sum+1, sum+N+1);

	printf("%u\n", sum[N]);



	return 0;
}