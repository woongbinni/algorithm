#include <stdio.h>

#define MAX 100001

typedef struct {
    int x;
    int y;
}point;

void merge(point *arr, int start, int mid, int end){
    point cp[MAX];
    int i=start, j=mid+1, k=0;
    while(i <= mid && j <= end){
        if(arr[i].y < arr[j].y || (arr[i].y == arr[j].y && arr[i].x < arr[j].x)) {
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

void mSort(point *arr, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mSort(arr, start, mid);
        mSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int N;
    point points[MAX];
    scanf("%d", &N);
    for(int i=0; i<N; ++i){
        scanf("%d%d", &(points[i].x), &(points[i].y));
    }
    mSort(points, 0, N-1);

    for(int i=0; i<N; ++i){
        printf("%d %d\n", points[i].x, points[i].y);
    }

    return 0;
}