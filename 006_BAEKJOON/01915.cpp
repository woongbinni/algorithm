#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M;
int map[1001][1001];
int dp[1001][1001];

int main()
{

    int ans = 0;

    scanf("%d %d", &N, &M);
    memset(map, 0x00, sizeof(map));
    memset(dp, 0x00, sizeof(dp));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 1)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {

            if (map[i][j] == 1)
            {
                // 검사
                if (dp[i - 1][j] != 0 && dp[i - 1][j - 1] != 0 && dp[i][j - 1] != 0)
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }

    printf("%d\n", ans * ans);

    return 0;
}