#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input[100000];
int sum[100001];

int main(void){
	int numCnt, testCnt;
	int from, to;
	memset(input, 0x00, sizeof(input));
	memset(sum, 0x00, sizeof(sum));
	scanf("%d", &numCnt);

	for(int i=0; i<numCnt; ++i){
		scanf("%d", &(input[i]));
		if(i == 0){
			sum[i+1] = input[i];
		}
		else{
			sum[i+1] = sum[i] + input[i];
		}
	}

	scanf("%d", &testCnt);

	for(int i=0; i<testCnt; ++i){
		scanf("%d %d", &from, &to);
		printf("%d\n", sum[to] - sum[from-1]);
	}

	return 0;
}
