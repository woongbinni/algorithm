#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

long long int fib[91];

void make_fib(void) {
    memset(fib, 0x00, sizeof(fib));
    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i <= 90; ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }

    return;
}
int main() {
    long input;

    make_fib();
    scanf("%lld", &input);

    printf("%lld\n", fib[input]);

    return 0;
}