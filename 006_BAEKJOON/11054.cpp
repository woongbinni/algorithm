#include <stdio.h>
#include <string.h>

int A[1001];
int dp[1001];
int reverse_dp[1001];

int main(){
	int N;
	int max;
	scanf("%d", &N);

	for(int i=1; i<=N; ++i){
		scanf("%d", &(A[i]));
		dp[i] = 1;
		reverse_dp[i] = 0;
	}

	for(int i=2; i<=N; ++i){
		for(int j=1; j<=i; ++j){
			if(A[j]<A[i] && dp[i] <= dp[j]){
				dp[i] = dp[j] + 1;
			}
		}
	}

	for(int i=N-1; i>=1; --i){
		for(int j=N; j>=i; --j){
			if(A[j]<A[i] && reverse_dp[i] <= reverse_dp[j]){
				reverse_dp[i] = reverse_dp[j] + 1;
			}
		}
	}

	max = dp[1] + reverse_dp[1];

	for(int i=2; i<=N; ++i){
		if(max < dp[i] + reverse_dp[i]){
			max = dp[i] + reverse_dp[i];
		}
	}

	printf("%d\n", max);

	return 0;
}