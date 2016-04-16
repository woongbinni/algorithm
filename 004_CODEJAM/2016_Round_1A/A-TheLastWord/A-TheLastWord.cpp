#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lastword[1001];
void getlastword(char* input, int len, int first_pos, int cur_pos) {
    char str[1001];
    char temp_str[1001];

    if (cur_pos == len) {
        if (strcmp(input, lastword) > 0)
            strcpy(lastword, input);

        return;
    }

    if (input[first_pos] > input[cur_pos]) {
        getlastword(input, len, first_pos, cur_pos + 1);
    }
    else {
        memset(str, 0x00, sizeof(str));
        memset(temp_str, 0x00, sizeof(temp_str));
        strncpy(temp_str, input, cur_pos);
        str[first_pos] = input[cur_pos];
        strcat(str, temp_str);
        strcat(str, &(input[cur_pos + 1]));
        getlastword(str, len, first_pos+1, cur_pos + 1);
    }

    return;
}

int main(void) {
    int test_case;
    char input[1001];
    int len;

    scanf("%d", &test_case);

    for (int idx = 1; idx <= test_case; ++idx) {
        memset(lastword, 0x00, sizeof(lastword));
        scanf("%s", input);
        len = strlen(input);

        getlastword(input, len, 0, 1);

        printf("Case #%d: %s\n", idx, lastword);
    }

    return 0;
}