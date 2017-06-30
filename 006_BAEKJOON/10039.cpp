#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum = 0;

int main(void){
    for(int i=0; i<5; ++i){
        int temp;
        scanf("%d", &temp);
        if(temp < 40){
            sum += 40;
        }
        else {
            sum += temp;
        }
    }

    printf("%d\n", sum/5);

    return 0;
}