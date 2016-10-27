/********************************************************************************
## 문제
2차원 평면상에 n개의 점이 주어졌을 때, 이 점들 중 가장 가까운 두 점을 구하는 프로그램을 작성하시오.
제한시간 : 2초

## 입력
첫째 줄에 자연수 n(2≤n≤500,000)이 주어진다. 다음 n개의 줄에는 차례로 각 점의 x, y좌표가 주어진다. 각각의 좌표는 절댓값이 10,000을 넘지 않는 정수이다.

## 출력
첫째 줄에 가장 가까운 두 점의 거리의 제곱을 출력한다.

## 입력 예제

4
0 0
10 10
0 10
10 0

출력 예제
100
********************************************************************************/


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Point {
    int x, y;
};
bool cmp(const Point &u, const Point &v) {
    return u.x < v.x;
}
int dist(Point &p1, Point &p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int main() {
    int n;
    scanf("%d",&n);
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    sort(a.begin(), a.end(), cmp);
    vector<Point> candidate = {a[0], a[1]};
    int ans = dist(a[0], a[1]);
    for (int i=2; i<n; i++) {
        Point now = a[i];
        for (auto it = candidate.begin(); it!=candidate.end(); ) {
            auto p = *it;
            int x = now.x - p.x;
            if (x*x > ans) {
                it = candidate.erase(it);
            } else {
                int d = dist(now, p);
                if (d < ans) {
                    ans = d;
                }
                it++;
            }
        }
        candidate.push_back(now);
    }
    printf("%d\n",ans);
    return 0;
}