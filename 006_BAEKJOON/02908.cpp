#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char num1[4], num2[4];
char result[4];
int scan_idx[3] = {2, 1, 0};

int main(void)
{
    int i;
    scanf("%s%s", num1, num2);

    for (i = 0; i < 3; ++i)
    {
        if (num1[scan_idx[i]] > num2[scan_idx[i]])
        {
            strcpy(result, num1);
            break;
        }
        else if (num1[scan_idx[i]] < num2[scan_idx[i]])
        {
            strcpy(result, num2);
            break;
        }
        else
        {
            continue;
        }
    }

    if (i == 3)
    {
        strcpy(result, num1);
    }

    for (i = 0; i < 3; ++i)
    {
        printf("%c", result[scan_idx[i]]);
    }
    printf("\n");

    return 0;
}