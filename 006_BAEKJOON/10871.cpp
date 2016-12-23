#include <stdio.h>

int arr[10001];
int main(void){
	int N, cmp, input;
	scanf("%d %d", &N, &cmp);

	for(int i=0; i<N; ++i){
		scanf("%d", &(arr[i]));
	}

	for(int i=0; i<N; ++i){
		if(arr[i] < cmp)
			printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}