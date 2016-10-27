/********************************************************************************
## 문제
정수가 N개 주어진다. 홀수번째 수가 주어질 때마다, 지금까지 주어진 수의 중앙값을 구하는 프로그램을 작성하여라.
예를 들어 1, 4, 5, 3, 6가 주어진다면, 첫번째 수인 1을 입력받을 때 중앙값이 1이고, 세 번째 수인 5를 입력받을 때까지의 중앙값이 4이고,
다섯번째 수인 6을 입력받을 때까지의 중앙값이 4이므로 1, 4, 4를 순서대로 출력하는 것이다.

## 입력
첫 번째 줄에 주어지는 정수의 개수 N이 주어진다. (1 ≤ N ≤ 99,999, N은 홀수)
두 번째 줄부터 N개의 줄에 걸쳐 각 줄에 하나씩 정수가 주어진다. (1 ≤ 주어지는 정수 ≤ 1,000,000,000)

## 출력
홀수번째 수를 입력받을 때마다 그 때까지 입력받은 정수들의 중앙값을 한 줄에 하나씩 출력한다.

## 입력 예제

7
1
9
5
3
2
8
8

## 출력 예제

1
5
3
5

********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, less<int> > maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;

int pop_arr[50001];

int N;

int main(void) {
	scanf("%d\n", &N);

	for (int i = 1; i <= N; ++i) {
		int temp;
		scanf("%d\n", &temp);

		if (minheap.size() == maxheap.size()) {
			maxheap.push(temp);
		}
		else {
			minheap.push(temp);
		}

		if (maxheap.size() != 0 && minheap.size() != 0) {
			while (maxheap.top() > minheap.top()) {
				int temp1 = maxheap.top();
				maxheap.pop();
				int temp2 = minheap.top();
				minheap.pop();
				maxheap.push(temp2);
				minheap.push(temp1);
			}

		}

		if (i % 2 == 1) {
			printf("%d\n", maxheap.top());
		}
	}

	return 0;
}