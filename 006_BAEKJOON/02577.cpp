#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int result [10];

int main(void){
    int A, B, C;
    memset(result, 0x00, sizeof(result));
    scanf("%d%d%d", &A, &B, &C);

    int mul = A * B * C;

    while(mul != 0){
        result[mul % 10] += 1;
        mul /= 10;
    }

    for(int i=0; i<10; ++i){
        printf("%d\n", result[i]);
    }

    return 0;
}