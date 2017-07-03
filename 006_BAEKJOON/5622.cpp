#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ascii_idx[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8 ,8 ,8, 9, 9, 9, 9};
char input[16];

int main(void){
    scanf("%s", input);
    int result = strlen(input);

    for(int i=0; i<strlen(input); ++i){
        result += ascii_idx[input[i]-'A'];
    }

    printf("%d\n", result);

    return 0;
}