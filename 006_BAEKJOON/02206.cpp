#include <stdio.h>
#include <iostream>
using namespace std;
#include <queue>

typedef struct _loc {
    int y;
    int x;
    int distance;
    int wall_break;
}loc;

int N, M;
char map[1001][1001];
bool visited[2][1001][1001];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int bfs() {
    loc start;
    start.y = 1;
    start.x = 1;
    start.distance = 1;
    start.wall_break = 0;
    visited[start.wall_break][start.y][start.x] = true;

    queue<loc> bfs_queue;
    bfs_queue.push(start);

    while(!bfs_queue.empty()){
        loc pop = bfs_queue.front();
        bfs_queue.pop();

        if(pop.y == N && pop.x == M) return pop.distance;
        
        for(int i=0; i<4; ++i){
            loc next;
            next.y = pop.y + dy[i];
            next.x = pop.x + dx[i];
            next.wall_break = pop.wall_break;
            next.distance = pop.distance + 1;
            if(next.y < 1 || next.y > N || next.x < 1 || next.x > M){
                continue;
            }
            if(visited[next.wall_break][next.y][next.x]){
                continue;
            }
            if(map[next.y][next.x] == '0'){
                visited[next.wall_break][next.y][next.x] = true;
                bfs_queue.push(next);
            }
            if(map[next.y][next.x] == '1' && next.wall_break == 0){
                next.wall_break = 1;
                visited[next.wall_break][next.y][next.x] = true;
                bfs_queue.push(next);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i) {
        char temp[1001];
        scanf("%s", temp);
        for(int j=1; j<=M; ++j){
            map[i][j] = temp[j-1];
        }
    }

    printf("%d\n", bfs());

    return 0;
}