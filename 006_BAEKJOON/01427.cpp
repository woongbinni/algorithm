#include <stdio.h>
#include <string.h>

void merge(char *arr, int start, int mid, int end){
    char cp[11];
    int i=start, j=mid+1, k=0;
    while(i <= mid && j <= end){
        if(arr[i] > arr[j]) {
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

void mSort(char *arr, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mSort(arr, start, mid);
        mSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    char N[11];
    scanf("%s", N);
    mSort(N, 0, strlen(N)-1);

    printf("%s\n", N);

    return 0;
}