#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asc[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int desc[8] = {8, 7, 6, 5, 4, 3, 2, 1};
int input[8];

int main(void){
    for(int i=0; i<8; ++i){
        scanf("%d", &(input[i]));
    }

    if(memcmp(input, asc, sizeof(int)*8) == 0){
        printf("ascending\n");
    }
    else if(memcmp(input, desc, sizeof(int)*8) == 0){
        printf("descending\n");
    }
    else{
        printf("mixed\n");
    }
    return 0;
}