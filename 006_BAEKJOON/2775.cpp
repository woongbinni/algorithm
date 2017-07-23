#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int apartment[16][16];
int T, k, n;

int main(void){
    memset(apartment, 0x00, sizeof(apartment));
    for(int i=1; i<=14; ++i){
        apartment[0][i] = i;
    }

    for(int i=1; i<=14; ++i){
        for(int j=1; j<=14; ++j){
            int sum = 0;
            for(int k=1; k<=j; ++k){
                sum += apartment[i-1][k];
            }
            apartment[i][j] = sum;
        }
    }

    scanf("%d", &T);

    for(int tc=1; tc <=T; ++tc){
        scanf("%d%d", &k, &n);
        printf("%d\n", apartment[k][n]);
    }

    return 0;
}