#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, M;
char map[52][52];
bool visited[52][52];
int dp[52][52];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int solve(int y, int x){
    if(y < 1 || y > N || x < 1 || x > M || map[y][x] == 'H'){
        return 0;
    }

    if(visited[y][x] == true){
        printf("-1\n");
        exit(0);
    }
    if(dp[y][x] != -1){
        return dp[y][x];
    }
    dp[y][x] = 0;

    visited[y][x] = true;
    int step = map[y][x]-'0';
    for(int i=0; i<4; ++i){
        int ny = y + (dy[i] * step);
        int nx = x + (dx[i] * step);
        dp[y][x] = max(dp[y][x], solve(ny, nx)+1);
    }
    visited[y][x] = false;
    return dp[y][x];
}

int main(){
    memset(visited, false, sizeof(visited));
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i){
        char str[52];
        scanf("%s", str);
        for(int j=1; j<=M; ++j){
            map[i][j] = str[j-1];
        }
    }

    int result = solve(1, 1);
    printf("%d\n", result);

    return 0;
}