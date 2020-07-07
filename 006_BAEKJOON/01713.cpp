#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

typedef struct _student {
    int pictureIdx;
    int recommendedCnt;
    int lastPictured;
} student;

int cmp(const void *a, const void *b){
    if((*(student *)a).recommendedCnt != (*(student *)b).recommendedCnt){
        return (*(student *)a).recommendedCnt > (*(student *)b).recommendedCnt;
    }
    else {
        return (*(student *)a).lastPictured > (*(student *)b).lastPictured;
    }
}

student students[101];
int pictured[20];
int N, R;

int main(){
    memset(pictured, 0x00, sizeof(pictured));
    memset(students, 0x00, sizeof(students));

    scanf("%d", &N);
    scanf("%d", &R);
    for(int i=0; i<R; ++i){
        int in;
        scanf("%d", &in);
        bool isSet = false;
        for(int j=0; j<N; ++j){
            if(pictured[j] == 0){
                pictured[j] = in;
                students[in].pictureIdx = j;
                students[in].recommendedCnt += 1;
                students[in].lastPictured = i;
                isSet = true;
                break;
            }
            if(pictured[j] == in){
                students[in].recommendedCnt += 1;
                isSet = true;
                break;
            }
        }
        if(isSet == false){
            student picOut[101];
            for(int j=0; j<N; ++j){
                picOut[j].pictureIdx = j;
                picOut[j].recommendedCnt = students[pictured[j]].recommendedCnt;
                picOut[j].lastPictured = students[pictured[j]].lastPictured;
            }
            qsort(picOut, N, sizeof(student), cmp);
            students[pictured[picOut[0].pictureIdx]].pictureIdx = 0;
            students[pictured[picOut[0].pictureIdx]].recommendedCnt = 0;
            pictured[picOut[0].pictureIdx] = in;
            students[in].pictureIdx = picOut[0].pictureIdx;
            students[in].recommendedCnt += 1;
            students[in].lastPictured = i;
        }
    }
    sort(pictured, &(pictured[N]));
    for(int i=0; i<N; ++i){
        printf("%d ", pictured[i]);
    }
    printf("\n");

    return 0;
}