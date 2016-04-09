#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char pancakes[110];
int flipCnt = 0;

bool isFinish(int pancakeNum) {
    for (int i = 0; i < pancakeNum; ++i) {
        if (pancakes[i] == '-')
            return false;
    }
    return true;
}

int flipPancake(int pancakeNum) {
    int i, j;

    if (isFinish(pancakeNum)) {
        return flipCnt;
    }

    char firstItem = pancakes[0];

    for (i = 0; i < pancakeNum; ++i) {
        if (pancakes[i] != firstItem)
            break;
    }

    if (i == pancakeNum) {
        flipCnt += 1;
        return flipCnt;
    }
    for (j = 0; j < i; ++j) {
        if (pancakes[j] == '-') {
            pancakes[j] = '+';
        }
        else {
            pancakes[j] = '-';
        }
    }
    flipCnt += 1;

    return flipPancake(pancakeNum);
}

int main(void) {
    int test_case;

    scanf("%d", &test_case);

    for (int idx = 1; idx <= test_case; ++idx) {
        memset(pancakes, 0x00, sizeof(pancakes));
        flipCnt = 0;

        scanf("%s", pancakes);

        printf("Case #%d: %d\n", idx, flipPancake(strlen(pancakes)));
    }

    return 0;
}
