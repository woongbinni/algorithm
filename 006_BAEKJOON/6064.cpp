#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int T, M, N, x, y;

int main(void){
    scanf("%d", &T);

    for(int tc=0; tc<T; ++tc){
        scanf("%d%d%d%d", &M, &N, &x, &y);

        int a = 0;
        int b = 0;
        int count = min(x, y);

        while(count <= (M * N)){
            if((M*a+x) < (N*b+y)){
                a += 1;
            }
            else if((M*a+x) > (N*b+y)){
                b += 1;
            }
            else{
                printf("%d\n", M*a+x);
                break;
            }
            count = min((M*a+x), (N*b+y));
        }
        if(count > (M*N)){
            printf("-1\n");
        }
    }

    return 0;
}