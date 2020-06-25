#include <stdio.h>
#include <string.h>

#define MAX 20001

typedef struct {
    char str[51];
    int len;
}word;

void merge(word *arr, int start, int mid, int end){
    word cp[MAX];
    int i=start, j=mid+1, k=0;
    while(i <= mid && j <= end){
        if(arr[i].len < arr[j].len || (arr[i].len == arr[j].len && strcmp(arr[i].str, arr[j].str) < 0)) {
            cp[k] = arr[i];
            i++;
        }
        else {
            cp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid) {
        cp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= end) {
        cp[k] = arr[j];
        k++;
        j++;
    }
    for(i=0; i<k; ++i){
        arr[start + i] = cp[i];
    }
}

void mSort(word *arr, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mSort(arr, start, mid);
        mSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int N;
    word dic[MAX];
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        scanf("%s", dic[i].str);
        dic[i].len = strlen(dic[i].str);
    }
    mSort(dic, 0, N-1);

    for(int i=0; i<N; ++i){
        if(i == 0){
            printf("%s\n", dic[i].str);
        }
        if(i > 0 && strcmp(dic[i-1].str, dic[i].str) != 0){
            printf("%s\n", dic[i].str);
        }
    }

    return 0;
}