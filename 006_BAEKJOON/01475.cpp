#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int used[10];

int main(void){
    char room_no[10];
    int result = 0;

    memset(used, 0x00, sizeof(used));
    scanf("%s", room_no);

    for(int i=0; i<strlen(room_no); ++i){
        if(room_no[i] == '6' || room_no[i] == '9'){
            if(used[6] < used[9]){
                used[6] += 1;
            }
            else {
                used[9] += 1;
            }
        }
        else {
            used[room_no[i]-'0'] += 1;
        }
    }

    for(int i=0; i<10; ++i){
        if(used[i] > result){
            result = used[i];
        }
    }

    printf("%d\n", result);

    return 0;
}