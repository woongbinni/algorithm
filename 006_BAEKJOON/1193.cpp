#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int remain;

int main(void)
{
    int i;
    scanf("%d", &remain);

    for (i = 1; i <= remain; ++i)
    {
        remain -= i;
    }

    if (remain == 0)
    {
        if (i % 2 == 0)
        {
            printf("%d/%d\n", 1, (i - 1));
        }
        else
        {
            printf("%d/%d\n", (i - 1), 1);
        }
    }
    else
    {
        if (i % 2 == 0)
        {
            printf("%d/%d\n", remain, (i + 1 - remain));
        }
        else
        {
            printf("%d/%d\n", (i + 1 - remain), remain);
        }
    }

    return 0;
}