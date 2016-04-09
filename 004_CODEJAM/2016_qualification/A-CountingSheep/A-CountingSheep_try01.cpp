#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool counted[10];

bool allCounted() {
    for (int i = 0; i < 10; ++i) {
        if (counted[i] == false)
            return false;
    }
    return true;
}

unsigned long countSheep(unsigned long N, int cnt) {
    unsigned long temp = N * cnt;
    while (temp != 0) {
        counted[temp % 10] = true;
        temp /= 10;
    }
    if (allCounted()) {
        return N * cnt;
    }
    else {
        return countSheep(N, cnt + 1);
    }
}

int main(void) {
    int test_case;
    scanf("%d", &test_case);

    for (int idx = 0; idx < test_case; ++idx) {
        memset(counted, false, sizeof(counted));

        unsigned long N;
        scanf("%lu", &N);

        if (N == 0) {
            printf("Case #%d: INSOMNIA\n", idx + 1);
        }
        else {
            printf("Case #%d: %lu\n", idx + 1, countSheep(N, 1));
        }
    }
    return 0;
}