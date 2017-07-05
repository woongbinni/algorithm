#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[101];

int main(void)
{
    int result = 0;
    scanf("%s", input);

    for (int i = 0; i < strlen(input); ++i)
    {
        if (input[i] == 'c' && input[i + 1] == '=')
        {
            result += 1;
            i += 1;
        }

        else if (input[i] == 'c' && input[i + 1] == '-')
        {
            result += 1;
            i += 1;
        }

        else if (input[i] == 'd' && input[i + 1] == 'z' && input[i + 2] == '=')
        {
            result += 1;
            i += 2;
        }

        else if (input[i] == 'd' && input[i + 1] == '-')
        {
            result += 1;
            i += 1;
        }

        else if (input[i] == 'l' && input[i + 1] == 'j')
        {
            result += 1;
            i += 1;
        }

        else if (input[i] == 'n' && input[i + 1] == 'j')
        {
            result += 1;
            i += 1;
        }

        else if (input[i] == 's' && input[i + 1] == '=')
        {
            result += 1;
            i += 1;
        }

        else if (input[i] == 'z' && input[i + 1] == '=')
        {
            result += 1;
            i += 1;
        }

        else
            result += 1;
    }

    printf("%d\n", result);

    return 0;
}