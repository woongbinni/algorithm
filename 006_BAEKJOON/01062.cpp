#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, K;
bool visited[30];
char input[51][17];
int readMax = 0;

void solve(int start, int count)
{
    if (count == K)
    {
        int canReadCnt = 0;

        for (int i = 0; i < N; ++i)
        {
            bool canRead = true;
            for (int j = 0; j < strlen(input[i]); ++j)
            {
                if (visited[input[i][j] - 'a'] == false)
                {
                    canRead = false;
                    break;
                }
            }
            if (canRead)
            {
                canReadCnt += 1;
            }
        }
        if (canReadCnt > readMax)
        {
            readMax = canReadCnt;
        }
        return;
    }

    for(int i=start; i<26; ++i){
        if(visited[i] == false){
            visited[i] = true;
            solve(i, count + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    memset(visited, false, sizeof(visited));

    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i)
    {
        scanf("%s", (char *)(input[i]));
    }

    if (K < 5)
    {
        printf("0\n");
    }
    else if (K >= 26)
    {
        printf("%d\n", N);
    }
    else
    {
        K -= 5;
        visited['a' - 'a'] = true;
        visited['c' - 'a'] = true;
        visited['i' - 'a'] = true;
        visited['n' - 'a'] = true;
        visited['t' - 'a'] = true;
        solve(0, 0);

        printf("%d\n", readMax);
    }

    return 0;
}
