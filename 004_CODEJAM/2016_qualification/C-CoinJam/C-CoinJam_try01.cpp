#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long prime[10000];
unsigned int prime_idx = 0;

void calcPrime(unsigned long from, unsigned long to) {
    unsigned long i, j;
    int flag;
    
    for (i = from; i <= to; ++i)
    {
        flag = 0;
        for (j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            prime[prime_idx] = i;
            prime_idx += 1;
        }
    }
}

int main(void) {
    int test_case;

    calcPrime(2, 11111111111111111111111111111111);

    for (int idx = 1; idx <= test_case; ++idx) {



        printf("Case #%d: TO PROVE\n", idx);
    }
}