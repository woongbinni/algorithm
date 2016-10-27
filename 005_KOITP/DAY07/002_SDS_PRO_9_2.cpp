/********************************************************************************
## 문제
이차원 평면에서 점 N개로 이루어진 다각형이 주어진다.
그리고 평면위의 점 P1, P2가 주어졌을때 점 P1, P2가 다각형의 외부에 있는지, 내부에 있는지 판별하는 프로그램을 작성하시오.
점 P1, P2 는 주어진 다각형의 선분 위에 존재하지는 않는다.

## 입력
첫째 줄에 다각형을 이루는 점의 갯수 (1 ≦ N ≦ 100,000)이 주어지고,
둘째 줄 부터 N개의 점의 정수 좌표(-10^9 ≦ x, y ≦ 10^9)가 입력으로 주어진다.
다각형의 좌표는 시계 방향 또는 반시계 방향 순서로 주어진다.
마지막 두 줄에는 점 P1, p2 의 좌표가 주어진다.

## 출력
첫째 줄에는 점 P1가 주어진 다각형 안에 존재한다면 "in", 밖에 존재한다면 "out"을 출력한다.
둘째 줄에는 점 P2가 주어진 다각형 안에 존재한다면 "in", 밖에 존재한다면 "out"을 출력한다.

## 입력 예시

4
1 1
1 3
3 3
3 1
0 0
2 2

## 출력 예시

out
in
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _point {
	double x;
	double y;
} point;

int N;
point points[100001];

bool isInside(point pos, int points_size) {
	//crosses는 점q와 오른쪽 반직선과 다각형과의 교점의 개수
	int crosses = 0;
	for (int i = 0 ; i < points_size ; i++) {
		int j = (i + 1) % points_size;
		//점 pos가 선분 (p[i], p[j])의 y좌표 사이에 있음
		if ((points[i].y > pos.y) != (points[j].y > pos.y) ) {
			//atX는 점 pos를 지나는 수평선과 선분 (p[i], p[j])의 교점
			double atX = (points[j].x - points[i].x) * (pos.y - points[i].y) / (points[j].y - points[i].y) + points[i].x;
			//atX가 오른쪽 반직선과의 교점이 맞으면 교점의 개수를 증가시킨다.
			if (pos.x < atX)
				crosses++;
		}
	}
	return crosses % 2 > 0;
}

int main(void) {

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%lf%lf", &(points[i].x), &(points[i].y));
	}

	for (int i = 0; i < 2; ++i) {
		point input;
		scanf("%lf%lf", &(input.x), &(input.y));
		if (isInside(input, N)) {
			printf("in\n");
		}
		else {
			printf("out\n");
		}
	}

	return 0;
}