#include <stdio.h>

int R, C;
int map[22][22];
bool visited[27];
int dx[4] = {0, +1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int result = 0;

void dfs(int y, int x, int distance){
    if(distance > result) {
        result = distance;
    }

    visited[map[y][x]-'A'] = true;
    for(int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= 1 && ny <= R && nx >= 1 && nx <= C && visited[map[ny][nx]-'A'] == false){
            dfs(ny, nx, distance + 1);
        }
    }
    visited[map[y][x]-'A'] = false;
}

int main () {
    scanf("%d%d", &R, &C);
    for(int i=1; i<=R; ++i){
        char temp[21];
        scanf("%s", temp);
        for(int j=1; j<=C; ++j){
            map[i][j] = temp[j-1];
        }
    }

    visited[map[1][1]-'A'] = true;
    dfs(1, 1, 1);
    printf("%d\n", result);

    return 0;
}