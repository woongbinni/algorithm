#include <iostream>
using namespace std;

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>

#define MAX_N 50001
#define MAX_PAR 20

int par[MAX_N][MAX_PAR]; // 부모 배열
int MAX[MAX_N][MAX_PAR]; // 최댓값 배열
int depth[MAX_N];        // 깊이 배열
bool visit[MAX_N];       // DFS 체크
// 입력 순서대로 우선 저장될 edge 정보
typedef struct _edge {
    int u;
    int v;
    int w;
} edge;

vector<edge> edges; // 입력 순서대로 저장
// MST를 위한 간선
vector<pair<int, int>> map[MAX_N];
// PQ에 들어갈 아이템 ( cost 순으로 정렬 됨 )
class PQItem
{
public:
    int now, nowDepth, prev, prevDist;
    PQItem() {}
    PQItem(int now, int nowDepth, int prev, int prevDist)
    {
        this->now = now;
        this->nowDepth = nowDepth;
        this->prev = prev;
        this->prevDist = prevDist;
    }
    bool operator<(const PQItem &b) const
    {
        return this->prevDist < b.prevDist;
    }
    bool operator>(const PQItem &b) const
    {
        return this->prevDist > b.prevDist;
    }
};
priority_queue<PQItem, vector<PQItem>, greater<>> pq;
// 입력받을 V, E
int V, E;
long long MST()
{
    int cnt = 0, ret = 0;
    pq.push(PQItem(1, 0, 1, 0)); // 1번노드부터 pq push
    while (!pq.empty())
    {
        PQItem top = pq.top();
        pq.pop();
        int now = top.now;
        int prev = top.prev;
        int prevDist = top.prevDist;
        int nowDepth = top.nowDepth;
        if (visit[now])
            continue;
        par[now][0] = prev;     // 1번째 부모
        MAX[now][0] = prevDist; // 부모와의 dist
        depth[now] = nowDepth;  // 현재 depth
        ret += prevDist;        // mst 간선의 총합을 위한 리턴값
        visit[now] = true;      // visit 체크
        cnt++;                  // MST의 존재여부 파악을 위함
        for (int i = 0; i < map[now].size(); ++i)
        {
            if (!visit[map[now][i].first])
            {
                pq.push(PQItem(map[now][i].first, nowDepth + 1, now, map[now][i].second));
            }
        }
    }
    if (cnt != V)
        ret = -1; // mst가 존재하지않는다 ( = 한 정점에서 모든 정점을 방문 할 수 없다 )
    return ret;
}
// lca 알고리즘
int LCA(int x, int y)
{
    if (depth[x] > depth[y]){
        int temp = x;
        x = y;
        y = temp;
    }
    for (int i = 19; i >= 0; i--)
    {
        int diff = depth[y] - depth[x];
        if (diff >= (1 << i))
        {
            y = par[y][i];
        }
    }
    if (x == y)
        return x;
    for (int i = 19; i >= 0; i--)
    {
        if (par[x][i] != par[y][i])
        {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}
// x노드와 y노드 사이의 간선의 최댓값 리턴
int getMax(int x, int y)
{
    int lca = LCA(x, y);
    int ret = -1;
    int x_to_lca = depth[x] - depth[lca];
    int y_to_lca = depth[y] - depth[lca];
    for (int i = 19; i >= 0; i--)
    {
        if (x_to_lca >= (1 << i))
        {
            ret = max(ret, MAX[x][i]);
            x_to_lca -= (1 << i);
            x = par[x][i];
        }
    }
    for (int i = 19; i >= 0; i--)
    {
        if (y_to_lca >= (1 << i))
        {
            ret = max(ret, MAX[y][i]);
            y_to_lca -= (1 << i);
            y = par[y][i];
        }
    }
    return ret;
}
// x노드와 y 노드 사이의 2번째로 큰 ( prevMax보다 첫번째로 작은 ) 값 리턴
// O(N)으로 탐색했음 ( 더좋은 방법이 있을 것 같음 )
int getSecondMax(int x, int y, int prevMax)
{
    int lca = LCA(x, y);
    int x_to_lca = depth[x] - depth[lca];
    int y_to_lca = depth[y] - depth[lca];
    int ret = -1;
    for (int i = 0; i < x_to_lca; ++i)
    {
        if (MAX[x][0] < prevMax)
        {
            ret = max(ret, MAX[x][0]);
        }
        x = par[x][0];
    }
    for (int i = 0; i < y_to_lca; ++i)
    {
        if (MAX[y][0] < prevMax)
        {
            ret = max(ret, MAX[y][0]);
        }
        y = par[y][0];
    }
    return ret;
}
int main()
{
    scanf("%d%d", &V, &E);

    for (int i = 0; i < E; ++i)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge in;
        in.u = a;
        in.v = b;
        in.w = w;
        edges.push_back(in);
        map[a].push_back({b, w});
        map[b].push_back({a, w});
    }
    long long minimum = MST();
    if (minimum == -1)
    {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 1; i <= 19; ++i)
    {
        for (int j = 1; j <= V; j++)
        {
            par[j][i] = par[par[j][i - 1]][i - 1];
            MAX[j][i] = max(MAX[j][i - 1], MAX[par[j][i - 1]][i - 1]);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        int maxE = getMax(u, v);
        // 가장 큰 값과 비교
        if (minimum - maxE + w > minimum)
        {
            if (ans > minimum - maxE + w)
                ans = minimum - maxE + w;
        }
        // 가장 큰 값이 현재 삽입하려는 간선의 weight와 같다면
        // 두번 째로 큰 간선을 찾는다
        else if (minimum - maxE + w == minimum)
        {
            int secondMaxE = getSecondMax(u, v, maxE);
            // 찾았 다면
            if (secondMaxE != -1)
            {
                if (ans > minimum - secondMaxE + w)
                    ans = minimum - secondMaxE + w;
            }
        }
    }
    if (ans == INT_MAX)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}
