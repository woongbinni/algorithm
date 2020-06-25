#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int T, S;
char input[21];
char result[210];

int main(void){
    scanf("%d", &T);

    for(int tc=0; tc<T; ++tc){
        int idx = 0;
        memset(result, '\0', sizeof(result));

        scanf("%d%s", &S, input);
        for(unsigned int i=0; i<strlen(input); ++i){
            for(int j=0; j<S; ++j){
                result[idx++] = input[i];
            }
        }

        printf("%s\n", result);
    }

    return 0;
}