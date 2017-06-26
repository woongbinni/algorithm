#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T;
char arr[81];

int main(void){
    scanf("%d", &T);

    for(int tc=0; tc<T; ++tc){
        int result = 0;
        int cur_mark = 0;

        scanf("%s", arr);
        for(int i=0; i<strlen(arr); ++i){
            if(arr[i] == 'O'){
                cur_mark += 1;
                result += cur_mark;
            }
            else{
                cur_mark = 0;
            }
        }
        printf("%d\n", result);
    }

    return 0;
}