#include <stdio.h>
#include <string.h>
using namespace std;

#define min(A, B) (((A) < (B)) ? (A) : (B))

int N, visitedAll;
int map[16][16];
int cost[16][1 << 16];

int tsp(int cur, int visited)
{
    if (visited == visitedAll)
    {
        if (map[cur][0] == 0)
            return 0x0FFFFFFF;
        else
            return map[cur][0];
    }

    if (cost[cur][visited] != -1)
        return cost[cur][visited];
    cost[cur][visited] = 0x0FFFFFFF;

    for (int i = 0; i < N; i++)
    {
        if (map[cur][i] == 0)
            continue;
        if ((visited & (1 << i)) == (1 << i))
            continue;

        cost[cur][visited] = min(cost[cur][visited], map[cur][i] + tsp(i, visited | 1 << i));
    }
    return cost[cur][visited];
}

int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    visitedAll = (1 << N) - 1;

    memset(cost, -1, sizeof(cost));
    printf("%d\n", tsp(0, 1));

    return 0;
}
