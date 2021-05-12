#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char input[2501];
bool palindrome[2501][2501];
unsigned int dp[2501];

int main()
{
    char temp[2501];
    scanf("%s", temp);
    int len = strlen(temp);
    memset(palindrome, false, sizeof(palindrome));

    for (int i = 1; i <= len; ++i)
    {
        input[i] = temp[i-1];
        palindrome[i][i] = true;
        dp[i] = 0xFFFFFFFF;
    }

    for (int i = 1; i <= (len - 1); ++i)
    {
        if (input[i] == input[i + 1])
        {
            palindrome[i][i + 1] = true;
        }
    }

    for (int i = 2; i <= (len - 1); i++)
    {
        for (int j = 1; j <= (len - i); j++)
        {
            if (palindrome[j + 1][j + i - 1] && input[j] == input[j + i])
            {
                palindrome[j][j + i] = true;
            }
        }
    }
    dp[0] = 0;

    for (int i = 1; i <= len; ++i)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 1; j < i; j++)
        {
            if (!palindrome[j][i])
                continue;
            dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }
    printf("%u\n", dp[len]);
    return 0;
}