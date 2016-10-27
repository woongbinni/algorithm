/********************************************************************************
## 문제

소들은 피크닉을 갈 예정이다! 각 존의 K(1 <= K <= 100)마리의 소들은 N(1 <= N <= 1,000) 개의 목초지중 하나의 목초지에서 풀을 뜯고 있다. 
이 목초지들을 목초지1 … 목초지 N이라고 명명하자. 그 목초지들은 M (1 <= M <= 10,000) 개의 단방향 길로 연결되어 있다. (어떠한 길도 출발지와 도착지가 같지 않다.)
소들은 그들의 피크닉동안 같은 목초지에서 모이기를 원한다. 하지만 몇마리의 소들은 모든 목초지에 도달할 수 없을 가능성이 있다.
(단방향 도로이기 때문에) 소들을 도와 얼마나 많은 목초지에서 모든 소들이 모일 수 있는지 계산해주자.

## 입력
첫번째 줄은 세개의 정수가 공백으로 구분되어 입력되어진다. :K,N,M
2번째줄부터 K+1번째 줄까지는 K마리의 소들의 처음 풀을 뜯고있는 위치가 각 줄에 하나씩 주어진다.
K+2번째 줄부터 M+K+1번째 줄까지는 단방향 도로의 정보 시작점S 와 끝점E가 입력으로 주어진다.

## 출력
모든 소가 모일 수 있는 가능한 목초지의 수를 출력해주자

## 예제 입력

2 4 4
2
3
1 2
1 4
2 3
3 4

## 예제 출력

2

## 힌트
모든 소들은 목초지 3,4에서 모일 수 있다.

이건 DFS로... 할 수 있을 듯..
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
using namespace std;

typedef struct _road_info{
	vector<int> destination;
}road_info;
int K, N, M;
road_info roads[1001];
bool connected[1001][1001];
list<int> cow;
int input[101];

void find_connected(int start, int cur){
	if(roads[cur].destination.size() == 0){
		return;
	}
	else{
		for(int i=0; i<roads[cur].destination.size(); ++i){
			if(connected[start][roads[cur].destination[i]] == false){
				connected[start][roads[cur].destination[i]] = true;
				find_connected(start, roads[cur].destination[i]);
			}
		}
	}

}

void solve(){
	while(cow.size() > 0){
		int temp = cow.front();
		find_connected(temp, temp);
		cow.remove(temp);
	}
}

int main(void){
	memset(connected, false, sizeof(connected));
	scanf("%d%d%d", &K, &N, &M);

	for(int i=1; i<=N; ++i){
		connected[i][i] = true;
	}

	for(int i=0; i<K; ++i){
		int temp;
		scanf("%d", &(input[i]));
		cow.push_back(input[i]);
	}

	for(int i=0; i<M; ++i){
		int from, to;
		scanf("%d%d", &from, &to);
		roads[from].destination.push_back(to);
		//connected[from][to] = true;
	}

	solve();

	// for(int i=0; i<K; ++i){
	// 	printf("%d | ", input[i]);
	// 	for(int j=1; j<=N; ++j){
	// 		printf("%d ", connected[input[i]][j]);
	// 	}
	// 	printf("\n");
	// }


	int result = 0;
	for(int i=1; i<=N; ++i){
		int j = 0;
		for(j=0; j<K; ++j){
			if(connected[input[j]][i] == false)
				break;
		}
		if(j == K)
			result += 1;
	}

	printf("%d\n", result);

	return 0;
}