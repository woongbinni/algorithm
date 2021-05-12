#include <stdio.h>
#include <string.h>

int N, M;
int S, E;
int input[2001];
bool dp[2001][2001];

int main()
{
    scanf("%d", &N);
    memset(dp, false, sizeof(dp));

    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &(input[i]));
        dp[i][i] = true;
    }

    for (int i = 1; i <= (N - 1); ++i)
    {
        if (input[i] == input[i + 1])
        {
            dp[i][i + 1] = true;
        }
    }

    for (int i = 2; i <= (N - 1); i++)
    {
        for (int j = 1; j <= (N - i); j++)
        {
            if (dp[j + 1][j + i - 1] && input[j] == input[j + i])
            {
                dp[j][j + i] = true;
            }
        }
    }

    scanf("%d", &M);
    for(int i=0; i<M; ++i){
        scanf("%d%d", &S, &E);
        printf("%d\n", (dp[S][E] ? 1 : 0));
    }
    return 0;
}