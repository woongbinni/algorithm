#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b){
	return (*(int*)b) - (*(int*)a);
}

int main(void){
	int arr[3];

	for(int i=0; i<3; ++i){
		scanf("%d", &(arr[i]));
	}

	qsort(arr, 3, sizeof(int), cmp);

	printf("%d\n", arr[1]);
}