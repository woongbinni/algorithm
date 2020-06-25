#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int T;
char input[101];
int last_index[26];
int result;

bool proof(char* input){
    bool retVal = true;
    memset(last_index, -1, sizeof(last_index));

    for(unsigned int i=0; i<strlen(input); ++i){
        if(last_index[input[i]-'a'] == -1){
            last_index[input[i]-'a'] = i;
        }
        else if(last_index[input[i]-'a'] + 1 == i){
            last_index[input[i]-'a'] = i;            
        }
        else{
            retVal = false;
            break;
        }
    }

    return retVal;
}

int main(void){
    result = 0;

    scanf("%d", &T);

    for(int i=0; i<T; ++i){
        scanf("%s", input);

        if(proof(input)){
            result += 1;
        }
    }
    printf("%d\n", result);

    return 0;
}