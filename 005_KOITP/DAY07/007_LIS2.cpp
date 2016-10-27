/********************************************************************************
## 문제

부분 수열(Subsequence)은 어떤 수열에서 순서를 유지하되, 그 중 일부 항만을 선택하여 만들 수 있는 수열이다. 
예를 들어, (1, 3, 2, 4)로 이루어진 수열이 있다면, (1, 3, 4), (1, 2, 4)등은 부분 수열이 될 수 있지만, (1, 2, 3)은 부분수열이 될 수 없다.
최장 증가 부분 수열(Longest Increasing Subsequence)은 어떤 수열의 부분 수열 중 각 항이 이전 항에 비해 증가하는 부분 수열을 의미한다. 
예를 들어, 수열 (1, 8, 4, 12, 2, 14, 6)의 최장 증가 부분 수열은 (1, 8, 12, 14), (1, 4, 12, 14)가 있다.
수열이 주어졌을 때, 해당 수열의 최장 증가 부분 수열의 길이를 알아내자.

## 입력

첫 번째 줄에 수열의 길이 N이 주어진다. (1 ≤ N ≤ 300,000)
두 번째 줄에 수열의 각 항의 값이 순서대로 주어진다. 주어지는 숫자는 32비트 정수형 이내의 숫자이다.

## 출력

첫 번째 줄에 주어진 수열의 최장 증가 부분 수열의 길이를 출력한다.

## 예제 입력

10
1 1 2 2 3 3 2 2 5 5

## 예제 출력

4

## 힌트

D[i] = max(D[j]+1, 1)  //단 j < i A(j) < A(i)
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int input[300001];
int dp[300001];

int main(void){
	scanf("%d", &N);
	int size = 1;
	int it;

	for(int i=1; i<=N; ++i){
		scanf("%d", &(input[i]));
		if(i == 1){
			dp[1] = input[i];
		}
		else{
			if(dp[size] < input[i]){
				size+=1;
				dp[size] = input[i];
				continue;
			}
			it=lower_bound(dp+1, dp+size+1, input[i]) - dp;
			dp[it] = input[i];
		}
	}

	printf("%d\n", size);

	return 0;
}