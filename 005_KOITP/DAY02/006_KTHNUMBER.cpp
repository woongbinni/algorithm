/********************************************************************************
## 문제
N개의 수가 주어진다. 이 수들을 오름차순 정렬했을 때, K번째에 위치하는 수를 알아내자.

## 입력
첫 번째 줄에 N, K가 공백으로 분리되어 주어진다. (1 ≤ K ≤ N ≤ 5,000,000)
두 번째 줄부터 N개의 줄에 걸쳐 N개의 정수가 주어진다. 각 정수는 -1,000,000,000 이상 1,000,000,000 이하이다.

## 출력
주어진 N개의 정수를 오름차순 정렬했을 때, K번째에 위치하는 수를 출력한다.

## 예제 입력
2 1
1 
2

## 예제 출력
1
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int N, K;
long long arr[5000001];

int main(void){
	long long temp;
	scanf("%d%d", &N, &K);

	for(int i=0; i<N; ++i){
		scanf("%lld", &(arr[i]));
		
	}

	sort(arr, arr+N);

	printf("%lld\n", arr[K-1]);

	return 0;
}