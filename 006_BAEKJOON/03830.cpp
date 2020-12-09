#include <stdio.h>

int N, M;
long long ans;
long long parents[100010];
long long diff[100010];

long long updateParents(long long a)
{
    if (parents[a] == a)
    {
        return a;
    }
    else
    {
        int t = parents[a];
        parents[a] = updateParents(parents[a]);
        diff[a] += diff[t];
        return parents[a];
    }
}

void unionSample(long long a, long long b, long long w)
{
    if (a > b)
    {
        long long temp; 
        temp = a;
        a = b;
        b = temp;
        w = 0-w;
    }
    updateParents(a);
    updateParents(b);
    long long x = diff[b];
    long long y = diff[a];
    a = updateParents(a);
    b = updateParents(b);
    parents[b] = a;
    diff[b] = w + y - x;
}

int main()
{
    while (true)
    {
        scanf("%d%d", &N, &M);
        if (N == 0 && M == 0)
        {
            break;
        }
        for (int i = 0; i <= N; i++)
        {
            parents[i] = i;
            diff[i] = 0;
        }

        for (int i = 0; i < M; i++)
        {
            char q[2];
            scanf("%s", q);
            if (q[0] == '!')
            {
                int a, b, w;
                scanf("%d%d%d", &a, &b, &w);
                unionSample(a, b, w);
            }
            else
            {
                int a, b;
                scanf("%d%d", &a, &b);
                if (updateParents(a) == updateParents(b))
                {
                    printf("%lld\n", diff[b] - diff[a]);
                }
                else
                {
                    printf("UNKNOWN\n");
                }
            }
        }
    }
    return 0;
}