#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, H, W, N;
int room_no;

int main(void)
{
    scanf("%d", &T);

    for(int tc=0; tc<T; ++tc){
        scanf("%d%d%d", &H, &W, &N);
        int floor = 0;
        int room_no = 1;
        for(int i=1; i<=N; ++i){
            floor += 1;
            if(floor > H){
                floor = 1;
                room_no += 1;
            }
        }
        printf("%d\n", (floor * 100) + room_no);
    }

    return 0;
}