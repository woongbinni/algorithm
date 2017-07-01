#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[1000001];
int cnt[26];
int max_val;
char max_char;

int main(void){
    int i;

    max_val = -1;
    memset(cnt, 0, sizeof(cnt));
    scanf("%s", input);

    for(i=0; i<strlen(input); ++i){
        if(input[i] >= 'a' && input[i] <= 'z'){
            cnt[input[i]-'a'] += 1;
        }
        else if(input[i] >= 'A' && input[i] <= 'Z'){
            cnt[input[i]-'A'] += 1;
        }
    }

    for(i=0; i<26; ++i){
        if(cnt[i] > max_val){
            max_val = cnt[i];
            max_char = 'A'+i;
        }
        else if(max_val != -1 && max_val == cnt[i]){
            max_char='?';
        }
    }

    if(i == 26){
        printf("%c\n", max_char);
    }

    return 0;
}