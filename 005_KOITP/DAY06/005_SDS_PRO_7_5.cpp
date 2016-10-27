/********************************************************************************
## 문제
정수 a와 m이 주어 졌을때, a의 m 거듭제곱을 1,000,000,007 로 나눈 나머지를 출력하는 문제이다.

## 입력
두 정수 a와 m이 주어진다. 1 <= a, m <= 2^63 - 1

## 출력
a 의 m 제곱 값을 10억 7로 나눈 나머지를 출력한다.

## 예제 입력
2 4

## 예제 출력
16
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007;
long long int a, m;

long long int pow(long long int a, long long int m){
	long long int i, j;
	long long int res = 1;
	long long int now = a;
	for(i=0, j=1; i<63; i++, j*=2){
		if((m&j) == j){
			res *= now;
			res %= MOD;
		}
		now *= now;
		now %= MOD;
	}
	return res;
}

int main(void){
	scanf("%lld%lld", &a, &m);

	printf("%lld\n", pow(a, m));

	return 0;
}