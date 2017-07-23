#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, M, N, x, y;

int main(void){
    scanf("%d", &T);

    for(int tc=0; tc<T; ++tc){
        scanf("%d%d%d%d", &M, &N, &x, &y);

        int temp_x = 1;
        int temp_y = 1;
        int result = 1;

        while(1){
            if(temp_x == M && temp_y == N){
                printf("-1\n");
                break;
            }
            else if(temp_x == x && temp_y == y){
                printf("%d\n", result);
                break;
            }
            else{
                temp_x += 1;
                temp_y += 1;
                if(temp_x > M){
                    temp_x = 1;
                }
                if(temp_y > N){
                    temp_y = 1;
                }
                result += 1;
            }
        }
    }

    return 0;
}