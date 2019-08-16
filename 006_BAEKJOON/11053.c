#include <stdio.h>
#include <string.h>

int A[1001];
int dp[1001];

int main(){
	int N;
	int max;
	memset(dp, 0x00, sizeof(dp));
	scanf("%d", &N);

	for(int i=1; i<=N; ++i){
		scanf("%d", &(A[i]));
		dp[i] = 1;
	}
	max = 1;

	for(int i=2; i<=N; ++i){
		for(int j=1; j<=i; ++j){
			if(A[j]<A[i] && dp[i] <= dp[j]){
				dp[i] = dp[j] + 1;
			}
		}
		if(max < dp[i]){
			max = dp[i];
		}
	}

	printf("%d\n", max);

	return 0;
}