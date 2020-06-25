#include <stdio.h>
#include <string.h>

int bits[101][101][2];

int main(void) {
    int T, n, k;

    memset(bits, 0x00, sizeof(bits));
    bits[1][0][0] = 1;
    bits[1][0][1] = 1;

    for(int i=2; i<101; ++i){
        for(int j=0; j<i; ++j){
            bits[i][j][0] = bits[i-1][j][0] + bits[i-1][j][1];
            bits[i][j][1] = bits[i-1][j][0] + bits[i-1][j-1][1];
        }
    }
    scanf("%d", &T);

    for(int i=0; i<T; ++i){
        scanf("%d%d", &n, &k);

        printf("%d\n", bits[n][k][0] + bits[n][k][1]);
    }

    return 0;
}