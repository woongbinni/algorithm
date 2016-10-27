/********************************************************************************
## 문제
다음 보드 게임은 N장의 카드를 갖고 시작한다.각각의 카드 앞면에는 1번부터 N번까지 번호가 순서대로 적혀 있고, 뒷면에는 빨간색(R), 녹색(G), 파란색(B) 중 하나의 색깔이 칠해져 있다.
항상 1번 마을로부터 시작하여 길이 연결되어 있는 이웃 마을로 이동해 가는데 한 번 이동할 때마다 갖고 있는 카드를 번호 순서대로 한 장씩 내야 한다. 
각 길은 빨간색(R), 녹색(G), 파란색(B) 중 하나의 색깔이 칠해져 있는데 만약 내놓은 카드의 색깔과 길의 색깔이 일치하면 10점의 점수를 얻는다.
예를 들어 N이 5이고 1번부터 5번까지의 카드 색깔이 R, G, R, B, G이라고 하자. 지도가 <그림 1>과 같이 주어졌다고 할 때,
1번 마을에서 시작하여 2번 마을로 가면 길의 색깔과 1번 카드의 색깔이 R로 일치하므로 10점을 받게 된다. 다음 3번 마을로 가면 마찬가지로 길의 색깔과 2번 카드의 색깔이 G로 일치하므로 10점을 추가로 받게 된다. 
이어 1번, 2번, 3번 마을로 이동하면 총 30점을 받는다. 하지만 1번 마을에서 시작하여 2번 마을을 거쳐 3번, 4번, 3번, 2번 마을로 이동하면 총 40점을 받게 된다.
갖고 있는 카드의 정보와 지도가 주어질 때 받을 수 있는 최대 점수를 출력하는 프로그램을 작성하시오.

## 입력
첫째 줄에 카드의 수 N이 주어진다.
둘째 줄에 N장의 카드의 색깔이 번호 순서대로 빈칸을 사이에 두고 주어진다.
셋째 줄에는 마을의 수 M과 길의 수 K가 빈칸을 사이에 두고 주어진다.
이어 K개의 줄에 길의 정보가 주어진다. 길의 정보는 양 끝 마을의 번호를 나타내는 서로 다른 두 개의 자연수와 길의 색깔이 빈칸을 사이에 두고 주어진다. 
두 마을을 잇는 길은 최대 1개이다. N은 1000이하의 자연수, M은 500이하의 자연수, K는 10000이하의 자연수이다. 카드의 색깔과 길의 색깔은 R, G, B중 하나이다.

## 출력
첫째 줄에 보드 게임에서 받을 수 있는 최대 점수를 출력한다.

예제 입력

5
R G R B G
4 5
1 2 R
1 3 G
2 3 G
1 4 R
4 3 B
예제 출력

40

## 힌트
벨먼포드 응용
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

typedef struct _road{
	int start;
	int end;
	char color[2];
}road;

typedef struct _town{
	vector<road> roads;
}town;

town towns[501];
char card[1001];
int N, M, K;
int result = 0;

void solve(int cur_pos, int card_idx, int cur_point){
	//printf("%d | %d | %d\n", cur_pos, card_idx, cur_point);
	if(card_idx > N){
		if(cur_point > result){
			result = cur_point;
		}
		return;
	}

	for(int i=0; i<towns[cur_pos].roads.size(); ++i){
		if(towns[cur_pos].roads[i].color[0] == card[cur_pos]){
			solve(towns[cur_pos].roads[i].end, card_idx+1, cur_point+10);
		}
		else{
			solve(towns[cur_pos].roads[i].end, card_idx+1, cur_point);	
		}
	}
}

int main(void){
	int i, j;
	scanf("%d", &N);

	for(i=1; i<=N; ++i){
		char temp[2];
		scanf("%s", temp);

		card[i] = temp[0];
	}

	// for(i=1; i<=N; ++i){
	// 	printf("%c ", (card[i]));
	// }
	// printf("\n");

	scanf("%d%d", &M, &K);
	for(i=0; i<K; ++i){
		road temp, rev_temp;
		scanf("%d%d%s", &(temp.start), &(temp.end), temp.color);
		// printf("%d %d %c\n", temp.start, temp.end, temp.color[0]);
		towns[temp.start].roads.push_back(temp);
		rev_temp.start = temp.end;
		rev_temp.end = temp.start;
		rev_temp.color[0] = temp.color[0];
		towns[rev_temp.start].roads.push_back(rev_temp);
	}

	solve(1, 1, 0);

	printf("%d\n", result);

	return 0;
}