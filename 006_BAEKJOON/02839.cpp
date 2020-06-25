#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int N;
    int result = -1;
    scanf("%d", &N);

    int i=0;

    while(i*5 <= N){
        if((N - i*5) %3 == 0){
            int temp = i + ((N - i*5) /3);
            if(result == -1){
                result = temp;
            }
            else if(result > temp){
                result = temp;
            }
        }
        ++i;
    }

    printf("%d\n", result);

    return 0;
}