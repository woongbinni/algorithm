/*
[문제]

원규와 현원이는 수업시간에 유명한 자료구조 중 하나인 최대 힙이라는 것에 대해 배웠다. 아래 그림은 최대 힙의 한 예이다.
 이처럼 최대힙은 인접한 노드간에 부모노드와 자식노드의 관계가 형성되어있으며, 부모노드는 최대 2개의 자식노드를 가지며, 부모노드의 값은 항상 자식노드들의 값보다 크다.
11이하의 음이 아닌 정수 N에 대하여, 1부터 2(N+1)-1까지의 자연수가 주어질 때, 이 숫자들을 빠짐없이 모두 사용하여 만들 수 있는 높이가 (N+1)인 최대 힙의 개수를 100,000,123으로 나눈 나머지를 출력하는 프로그램을 작성하시오.
(예시) N이 1인 경우 아래 두가지의 방법이 존재한다.

                  3                     3
                1   2                2   1

 
[입력]
최초 테스트케이스의 개수 T가 주어지며, 다음 줄부터 T개의 테스트 케이스가 주어진다. 각 테스트 케이스마다 자연수 N(0≤N≤11) 값이 주어진다.

[출력]
각각의 테스트 케이스에 대하여 #x (x는 테스트 케이스 번호, 1부터 시작)을 출력하고 공백을 하나 둔 다음, 프로그램의 결과값을 출력한다.

[입출력 예]
(입력)
2
1
2

(출력)
#1 2
#2 80

*/


#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int T, N;
int combination[4097][4097];
long long DP[12];
long long mod = 100000123;

int main(void)
{
	scanf("%d", &T);

	for (int i = 0; i < 4097; i++)
	{
		combination[i][0] = 1;
		combination[i][i] = 1;
	}

	for (int i = 2; i < 4097; i++)
	{
		for (int j = 1; j < i; j++)
		{
			combination[i][j] = (combination[i - 1][j - 1] + combination[i - 1][j]) % mod;
		}
	}

	DP[0] = 1;
	DP[1] = 2;
	for (int i = 2; i < 12; i++)
	{
		int st = (int)(pow(2, i) - 1);
		int c = st - 1;
		int ed = (int)(pow(2, i + 1) - 2);
		long long temp = 0;
		for (int j = st; j <= ed; j++)
		{
			temp += combination[j - 1][c];
			temp %= mod;
		}
		DP[i] = (((DP[i - 1] * DP[i - 1]) % mod) * temp) % mod;
	}

	for(int tc=1; tc<=T; ++tc){
		scanf("%d", &N);
		printf("#%d %lld\n", tc, DP[N]);
	}

	return 0;
}