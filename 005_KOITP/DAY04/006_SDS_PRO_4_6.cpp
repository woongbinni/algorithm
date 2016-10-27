/********************************************************************************

## 문제
그의 많은 농장들을 탐험하던중, 존은 몇 개의 놀라운 웜홀을 발견했다. 웜홀은 현재 농장에서 다른 농장으로의 이상한 단방향 통로로써 
당신이 들어갔던 시간보다 이전시간으로 시간을 되돌린다. 존의 농장은 N개의 농장과 M개의 양방향 도로, W개의 웜홀로 구성되어있다. 
그리고 각 농장은 편의상 농장1, 농장2, … ,농장 N이라고 이름붙여주자.
존은 갑자기 현재위치에서 출발해서 여행을 하다 다시 현재위치로 돌아왔을 때 시간이 되돌아 가 있는 경우가 있는지 궁금해졌다. 
존을 도와 시간을 되돌리는 여행이 가능한지 구하는 프로그램을 작성하여라.

## 입력
첫 번째 줄에 테스트케이스의 개수 T가 주어진다. (1 ≤ T ≤ 5)
각 테스트 케이스의 첫 번째 줄에 농장의 수 N, 도로의 수 M, 웜홀의 수 W가 주어진다. (1 ≤ N ≤ 500, 1 ≤ M ≤ 2,500, 1 ≤ W ≤ 200)
각 테스트 케이스의 두 번째 줄부터 M개의 줄에 걸쳐 양방향 도로의 정보 s, e, t가 공백으로 분리되어 주어진다. 
s, e는 해당 도로가 잇는 지점의 번호, t는 해당 도로를 통해 이동하는데 걸리는 시간을 의미한다. (1 ≤ s, e ≤ N, 1 ≤ t ≤ 10,000)
각 테스트 케이스의 (M + 2) 번째 줄부터 W개의 줄에 걸쳐 웜홀의 정보 s, e, t가 공백으로 분리되어 주어진다. 
s는 해당 웜홀의 시작지점, e는 해당 웜홀의 도착 지점, t는 줄어드는 시간을 의미한다. (1 ≤ s, e ≤ N, 1 ≤ t ≤ 10,000)
두 지점을 연결하는 도로가 한 개보다 많을 수도 있다.

## 출력
각 테스트 케이스마다 첫 번째 줄에 시간을 돌릴 수 있다면 YES, 불가능하다면 NO를 출력한다.

## 예제 입력

2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8

## 예제 출력

NO
YES


## 힌트 벨먼포드 알고리즘


#include <cstdio>
#include <vector>
 
using namespace std;
 
struct Edge {
    int st, en, cost;
};
 
const int INF = 1000000000;
 
vector<Edge> edges;
 
int N, M, W;
 
bool hasNegative() {
    vector<int> dist(N + 1, INF);
    dist[1] = 0;
 
    for (int i = 0; i < N + 1; i ++) {
        bool updated = false;
 
        for (auto &e : edges) {
            if (dist[e.en] > dist[e.st] + e.cost) {
                dist[e.en] = dist[e.st] + e.cost;
                updated = true;
            }
        }
        if (!updated) {
            return false;
        }
    }
 
    return true;
}
 
int main() {
    int T;
    scanf("%d", &T);
 
    while (T --) {
        scanf("%d %d %d", &N, &M, &W);
 
        for (int i = 0; i < M; i ++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back({a, b, c});
            edges.push_back({b, a, c});
        }
 
        for (int i = 0; i < W; i ++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            edges.push_back({a, b, -c});
        }
 
        if (hasNegative()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        edges.clear();
    }
    return 0;
}
********************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

typedef struct _edge {
    int st, en, cost;
}edge;
 
const int INF = 1000000000;
 
vector<edge> edges;
 
int N, M, W;
 
bool hasNegative() {
    vector<int> dist(N + 1, INF);
    dist[1] = 0;
 
    for (int i = 0; i < N + 1; i ++) {
        bool updated = false;
 
        for (int j = 0; j<edges.size(); j++) {
            if (dist[edges[j].en] > dist[edges[j].st] + edges[j].cost) {
                dist[edges[j].en] = dist[edges[j].st] + edges[j].cost;
                updated = true;
            }
        }
        if (!updated) {
            return false;
        }
    }
 
    return true;
}
 
int main() {
    int T;
    scanf("%d", &T);
 
    while (T --) {
        scanf("%d %d %d", &N, &M, &W);
 
        for (int i = 0; i < M; i ++) {
            edge temp1, temp2;
            scanf("%d %d %d", &(temp1.st), &(temp1.en), &(temp1.cost));
            temp2.st = temp1.en;
            temp2.en = temp1.st;
            temp2.cost = temp1.cost;

            edges.push_back(temp1);
            edges.push_back(temp2);
        }
 
        for (int i = 0; i < W; i ++) {
            edge temp;
            scanf("%d %d %d", &(temp.st), &(temp.en), &(temp.cost));
            temp.cost *= -1;
            edges.push_back(temp);
        }
 
        if (hasNegative()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        edges.clear();
    }
    return 0;
}
