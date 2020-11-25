#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count[28];

int compare(const void *a, const void *b) 
{ 
    return *(int*)b - *(int*)a;
}

int main(){
    int N;
    memset(count, 0x00, sizeof(count));

    scanf("%d", &N);
    for(int i=0 ; i<N; ++i) {
        char input[10];
        scanf("%s", input);
        int mul = 1;
        for(int j=strlen(input)-1; j>=0; --j){
            count[input[j]-'A'] += mul;
            mul *= 10;
        }
    }

    qsort(count, 27, sizeof(int), compare);

    int mul = 9;
    int result = 0;
    for(int i=0; i<27; ++i){
        if(count[i] == 0){
            break;
        }
        else {
            result += (mul * count[i]);
            mul -= 1;
        }
    }

    printf("%d\n", result);

    return 0;
}