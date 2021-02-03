#include <stdio.h>
#include <string.h>

int N, M;
bool visited[301][301];
int map[2][301][301];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int age = 0;
int land_cnt = 0;

void next_year()
{
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            if(map[age%2][i][j] > 0) {
                int melt = 0;
                for(int k=0; k<4; ++k){
                    if(map[age%2][i+dy[k]][j+dx[k]] == 0){
                        melt += 1;
                    }
                }
                map[(age+1)%2][i][j] = map[age%2][i][j] - melt;
                if(map[(age+1)%2][i][j] < 0){
                    map[(age+1)%2][i][j] = 0;
                }
            }
            else {
                map[(age+1)%2][i][j] = 0;
            }
        }
    }
}

void print_ice()
{
    printf("\n");
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=M; ++j) {
            printf("%d ", map[age%2][i][j]);
        }
        printf("\n");
    }
}


void dfs(int y, int x)
{
    // printf("visit: %d %d\n", y, x);
    visited[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && map[age % 2][ny][nx] > 0 && visited[ny][nx] == false)
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    memset(map, 0x00, sizeof(map));
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            scanf("%d", &(map[0][i][j]));
        }
    }
    // print_ice();

    while (true)
    {
        memset(visited, false, sizeof(visited));
        land_cnt = 0;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                if (map[age % 2][i][j] > 0 && visited[i][j] == false)
                {
                    land_cnt += 1;
                    if (land_cnt == 2)
                    {
                        printf("%d\n", age);
                        return 0;
                    }
                    dfs(i, j);
                }
            }
        }
        if(land_cnt == 0){
            printf("0\n");
            break;
        }
        next_year();
        age+=1;
        // print_ice();
    }

    return 0;
}