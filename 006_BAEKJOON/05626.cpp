#include <stdio.h>
#define MIN(A, B) (((A) < (B)) ? (A) : (B))

int podium[10001];
int dp[2][5001];
int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &(podium[i]));
        if (podium[i] > MIN(i, (N - 1) - i))
        {
            printf("0\n");
            return 0;
        }
    }

    dp[0][0] = dp[1][0] = 1;

    for (int i = 0; i < N; ++i)
    {
        int cur = i % 2;
        int pre = (cur + 1) % 2;
        for (int x = 0; x < (N+1) / 2; ++x)
            dp[cur][x] = 0;

        if (podium[i] == -1)
        {
            for (int x = 0; x < (N+1) / 2; ++x)
            {
                if (x > MIN(i, (N - 1) - i))
                    break;

                for (int k = -1; k < 2; ++k)
                {
                    int prex = x + k;
                    if (prex < 0)
                        continue;

                    dp[cur][x] += dp[pre][prex];
                    dp[cur][x] %= 1000000007;
                }
            }
        }
        else
        {
            for (int k = -1; k < 2; ++k)
            {
                int prex = podium[i] + k;
                if (prex < 0)
                    continue;

                dp[cur][podium[i]] += dp[pre][prex];
                dp[cur][podium[i]] %= 1000000007;
            }
        }
        if (i == N - 1)
            printf("%d\n", dp[cur][0] % 1000000007);
    }

    return 0;
}