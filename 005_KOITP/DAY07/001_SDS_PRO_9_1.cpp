/********************************************************************************
## 문제
이차원 평면에 점 N개로 이루어진 단순 다각형이 주어진다. 이때 이 다각형이 평면에서 차지하는 면적을 구해보자. 다각형의 면적은 반드시 0보다 크다.

## 입력
첫째 줄에 다각형을 이루는 점의 갯수 (1 ≦ N ≦ 100,000)이 주어지고,
둘째 줄 부터 N개의 점의 정수 좌표(-10^9 ≦ x, y ≦ 10^9)가 입력으로 주어진다.
다각형의 좌표는 시계 방향 또는 반시계 방향 순서로 주어진다.

## 출력
주어진 단순 다각형이 이루는 넓이를 소수 둘째 자리에서 반올림 한 값을 출력한다.

## 입력 예시

3
1 1
1 2
2 1

## 출력 예시

0.5
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct _point {
	double x;
	double y;
} point;

int N;
point points[100001];

int main(void) {
	scanf("%d", &N);
	double result = 0;

	for (int i = 0; i < N; ++i) {
		scanf("%lf%lf", &(points[i].x), &(points[i].y));
		if (i == 0) continue;
		result += (points[i - 1].x * points[i].y);
		result -= (points[i - 1].y * points[i].x);
	}
	result += (points[N - 1].x * points[0].y);
	result -= (points[N - 1].y * points[0].x);

	result = 0.5 * abs(result);

	printf("%.1lf\n", result);

	return 0;
}