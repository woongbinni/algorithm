/********************************************************************************
## 문제
2차원 평면에 N개의 점이 주어졌을 때, 이들 중 몇 개의 점을 골라 볼록 다각형을 만드는데, 나머지 모든 점을 내부에 포함하도록 할 수 있다. 이를 볼록 껍질 (Convex Hull) 이라 한다.
N개의 점이 주어질 때 볼록껍질을 이루는 점의 개수를 구하여라. 만약 볼록껍질을 이루는 한 선분에 3개 이상의 점이 포함된 경우, 양 끝점만을 센다.

## 입력
첫 번째 줄에 점의 개수 N이 주어진다. (3 ≤ N ≤ 100,000)
두 번째 줄부터 N개의 줄에 걸쳐 각 점의 좌표를 의미하는 두 정수 x, y가 공백으로 분리되어 주어진다. (-40,000 ≤ x, y ≤ 40,000) 각 점은 모두 다른 위치에 있으며, 모든 점이 한 직선위에 있는 경우는 없다.

## 출력
첫 번째 줄에 볼록껍질을 이루는 점의 개수를 출력한다.

## 예제 입력

8
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2

## 예제 출력

5
********************************************************************************/


#include <stdio.h>
#include <cstdlib>
#include <list>
#include <algorithm>
using namespace std;

typedef struct _point {
	int idx;
	long long x;
	long long y;
} point;

int N;
point points[100001];
list<point> hull_stack;

int calc_ccw(point a, point b, point c) {
	long long ccw = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (ccw > 0) return 1;
	if (ccw < 0) return -1;
	return 0;
}

int calc_angle(int i) {
	list<point>::iterator iter = hull_stack.begin();
	point c = points[i];
	point b = *iter;
	iter++;
	point a = *iter;

	return calc_ccw(a, b, c);
}

bool cmp(point b, point c) {
	point a = points[0];

	int ccw = calc_ccw(a, b, c);

	if (ccw) {
		return ccw > 0;
	}
	return abs((b.x - a.x) + (b.y - a.y)) < abs((c.x - a.x) + (c.y - a.y));
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%lld%lld", &(points[i].x), &(points[i].y));
		points[i].idx = i;

	}

	for (int i = 1; i < N; ++i) {
		if (points[0].y > points[i].y || (points[0].y == points[i].y && points[0].x > points[i].x))
			swap(points[0], points[i]);
	}

	 sort(points + 1, points + N, cmp);

	for (int i = 0; i < N; ++i) {

		if (i < 1) {
			hull_stack.push_front(points[i]);
		}
		else {
			while (hull_stack.size() > 1 && calc_angle(i) <= 0) {
				hull_stack.pop_front();
			}
			hull_stack.push_front(points[i]);
		}
	}

	// while (calc_angle(0) < 0) {
	// 	hull_stack.pop_front();
	// }

	printf("%lu\n", hull_stack.size());

	return 0;
}