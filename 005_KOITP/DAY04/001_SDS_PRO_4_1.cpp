/********************************************************************************
## 문제
 
강희는 정신을 차려보니 낯선 유령선에 납치당해 있었다. 강희는 유령들이 자고 있는 낮 시간에 몰래 유령선에 있는 구명보트를 이용해 탈출하려고 한다.
유령선의 갑판은 동일한 크기의 정사각형 모양 판자가 가로로 W개, 세로로 H개 이어진 모양으로 되어 있다. 강희는 현재 서 있는 위치에서 상하좌우로 움직일 수 있다.
유령선은 매우 낡았기 때문에 강희가 딛고 있는 판자를 벗어나면 판자가 부서지고 만다. 심지어 이미 부서져 있는 판자도 존재한다. 물론 강희는 유령이 아니기 때문에 부서진 판자는 걸어서 지나갈 수 없다.
판자가 너무 많이 부서지면 유령들이 화를 내기 때문에 강희는 가장 작은 개수의 판자를 파괴하면서 유령선에서 탈출하려고 한다. 강희가 유령선에서 탈출하는 것을 돕는 프로그램을 작성하자.
 
시간제한: 1초
 
## 입력
 
첫 줄에 두 정수 W(2<=W<=1500)와 H(2<=H<=1500)가 공백을 사이에 두고 주어진다. 그 다음 줄부터 H줄마다 각각 W개의 문자가 주어진다.
각 문자는 X, O, S, E 중 하나며 전체 문자들 중 S와 E는 정확히 하나임이 보장된다.
X는 처음부터 부서진 판자를 나타낸다.
O는 강희가 밟고 지나갈 수 있지만, 밟은 이후 부서지는 판자를 나타낸다.
S는 처음 강희가 서 있는 판자의 위치를 나타낸다.
E는 유령선의 구명보트 위치를 나타낸다.
 
## 출력
 
강희가 판자를 최소 개수로 파괴하면서 유령선에서 탈출할 때 파괴되는 판자의 개수를 첫 줄에 출력하라.
만약 강희가 유령선에서 탈출할 수 있는 방법이 없는 경우, -1을 출력하라.
 
## 예제 입력 1
 
4 3
OOSO
OXXO
OOEO
 
## 예제 출력 1
 
4
 
## 예제 설명 1
 
총 두 가지 탈출 경로가 존재한다.
강희가 (좌, 좌, 하, 하, 우, 우)로 움직이는 경우 6개의 판자가 부서진다.
강희가 (우, 하, 하, 좌)로 움직이는 경우 4개의 판자가 부서진다.
따라서 답은 4이다.
 
## 예제 입력 2
 
3 3
EXX
XSO
OOX
 
## 예제 출력 2
 
-1
 
 
## 가중치가 같은 그래프로 생각하고 탐색 (bfs)
 
 
********************************************************************************/
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
using namespace std;
 
typedef struct _point{
	int x;
	int y;
	int cost;
}point;

int W, H;
point start_point, end_point;
list<point> bfs_queue;
char graph[1501][1501];
int result[1501][1501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
 
void solve() {
	point cur = bfs_queue.front();
	bfs_queue.pop_front();
    if (result[cur.x][cur.y] > cur.cost) {
        result[cur.x][cur.y] = cur.cost;
    }
    else {
        return;
    }
 
    if (cur.x == end_point.x && cur.y == end_point.y) {
        return;
    }
 
    for (int i = 0; i < 4; ++i) {
        if ((graph[cur.x + dx[i]][cur.y + dy[i]] != 0) && (graph[cur.x + dx[i]][cur.y + dy[i]] != 'X') && (graph[cur.x + dx[i]][cur.y + dy[i]] != 'S')) {
            if (result[cur.x][cur.y] + 1 < result[(cur.x + dx[i])][(cur.y + dy[i])]) {
            	point temp;
            	temp.x = cur.x + dx[i];
            	temp.y = cur.y + dy[i];
            	temp.cost = cur.cost + 1;
                bfs_queue.push_back(temp);
            }
        }
    }
}
 
int main(void) {
    scanf("%d%d", &W, &H);
    memset(graph, 0x00, sizeof(graph));
 
    for (int i = 1; i <= H; ++i) {
        char temp_str[1501];
        scanf("%s", temp_str);
        for (int j = 1; j <= W; ++j) {
            graph[i][j] = temp_str[j - 1];
            result[i][j] = 0x7FFFFFFF;
            if (temp_str[j - 1] == 'S') {
                start_point.x = i;
                start_point.y = j;
                start_point.cost = 0;
            }
            else if (temp_str[j - 1] == 'E') {
                end_point.x = i;
                end_point.y = j;
            }
        }
    }
 
 	bfs_queue.push_back(start_point);
 	while(bfs_queue.size() > 0){
 		solve();
 	} 
 
    if (result[end_point.x][end_point.y] == 0x7FFFFFFF) {
        printf("-1\n");
    }
    else {
        printf("%d\n", result[end_point.x][end_point.y]);
    }
    return 0;
}