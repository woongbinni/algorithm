#include <stdio.h>
#include <string.h>
#define UNKNOWN 0x00
#define TALL 1
#define SMALL -1

int N, M;
int floid[501][501];

int main()
{
    memset(floid, UNKNOWN, sizeof(floid));
    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        floid[a][b] = TALL;
        floid[b][a] = SMALL;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (floid[i][j] == UNKNOWN)
                {
                    if (floid[i][k] == TALL && floid[k][j] == TALL)
                        floid[i][j] = TALL;
                    if (floid[i][k] == SMALL && floid[k][j] == SMALL)
                        floid[i][j] = SMALL;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++)
    {
        bool existUNKNOWN = false;
        for (int j = 1; j <= N; j++)
        {
            if (i != j && floid[i][j] == UNKNOWN)
            {
                existUNKNOWN = true;
                break;
            }
        }
        if (!existUNKNOWN)
        {
            answer += 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}