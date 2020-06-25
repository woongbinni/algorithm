#include <stdio.h>

int main(void)
{
    int N, M;
    int card[100];
    int ret = 0;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &(card[i]));
    }

    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = i + 1; j < N - 1; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                if (card[i] + card[j] + card[k] <= M)
                {
                    if (ret < card[i] + card[j] + card[k])
                    {
                        ret = card[i] + card[j] + card[k];
                    }
                }
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}