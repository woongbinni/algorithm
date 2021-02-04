#include <iostream>
using namespace std;
#include <queue>
#include <stdio.h>
#include <string.h>

typedef struct _loc {
    int y;
    int x;
}loc;

int N;
char map[101][101];
bool visited[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int result_1 = 0;
int result_2 = 0;

void bfs(int y, int x, char color){
    loc item;
    item.y = y;
    item.x = x;

    queue<loc> bfs_queue;
    visited[item.y][item.x] = true;
    bfs_queue.push(item);

    while(!bfs_queue.empty()){
        loc pop = bfs_queue.front();
        bfs_queue.pop();
        for(int i=0; i<4; ++i) {
            int ny = pop.y + dy[i];
            int nx = pop.x + dx[i];
            if(ny >= 1 && ny <= N && nx >= 1 && ny <= N && visited[ny][nx] == false && map[ny][nx] == color){
                loc temp;
                temp.y = ny;
                temp.x = nx;
                visited[temp.y][temp.x] = true;
                bfs_queue.push(temp);
            } 
        }
    }
}

int main() {
    scanf("%d", &N);

    for(int i=1; i<=N; ++i) {
        char temp[101];
        scanf("%s", temp);
        for(int j=1; j<=N; ++j) {
            map[i][j] = temp[j-1];
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(visited[i][j] == false){
                bfs(i, j, map[i][j]);
                result_2 += 1;
            }
        }
    }

    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(map[i][j] == 'G'){
                map[i][j] = 'R';
            }
        }
    }

    memset(visited, false, sizeof(visited));

    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(visited[i][j] == false){
                bfs(i, j, map[i][j]);
                result_1 += 1;
            }
        }
    }

    printf("%d %d\n", result_2, result_1);

    return 0;
}