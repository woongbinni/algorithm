#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
 
int N, Answer;
int map[501][501];   // 최초 입력을 받는 대나무숲 정보
int dp[501][501];    // dp[x][y] = 판다를 x,y에 놓았을때 최대로 살수 있는 일수
 
int dx[] = { 0, 1, 0, -1 }; //4방향 탐색 x축
int dy[] = { 1, 0, -1, 0 }; //4방향 탐색 y축
 
int dfs(int x, int y)
{
    if (dp[x][y] != 0) return dp[x][y];
    dp[x][y] = 1;
 
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
        {
            if (map[x][y] < map[nx][ny])
            {
                dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
            }
        }
    }
    return dp[x][y];
}
   
int main(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &(map[i][j]));
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            Answer = max(Answer, dfs(i, j));
        }
    }
    printf("%d\n", Answer);

    return 0;
}
