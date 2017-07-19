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
        room_no = N % H;
        room_no *= 100;
        if(room_no == 0){
            room_no = 100;
        }
        room_no += (N / H) + 1;
        printf("%d\n", room_no);
    }

    return 0;
}