#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

typedef struct _ticket {
    int d;
    int v;
    int c;
} ticket;

// 오름차순 정렬
struct cmp{
    bool operator()(ticket a, ticket b){
        if (a.d == b.d) {
            if(a.v == b.v) {
                return a.c > b.c;
            }
            return a.v > b.v;
        }
        return a.d > b.d;
    }
};
#define INF 0xFFFFFFFF

int T, N, M, K;
int u, v, c, d;
unsigned int dp[101][10001], ans;
vector<ticket> airport[101];


void dijkstra()
{
	priority_queue<ticket, vector<ticket>, cmp> pq;

	dp[1][0] = 0;
    ticket first = { 0, 1, 0 };
	pq.push(first); // 누적 시간, 출발지, 누적 비용 

	while (!pq.empty())
	{
		int time = pq.top().d; // 누적 시간
		int now = pq.top().v; // 현재 공항
		int money = pq.top().c; // 누적 비용
		
		pq.pop();

		if (dp[now][money] < time) continue;

		for (int i = 0; i < airport[now].size(); i++) // airport의 티켓을 모두 조회.
		{
			int next_time = time + airport[now][i].d; // 소요 시간
			int next = airport[now][i].v; // 다음 공항
			int next_money = money + airport[now][i].c; // 소요 비용
			

			// 지원 비용으로 갈 수 없을 경우 pass
			if (next_money > M) continue;

			// 해당 공항에 해당 비용으로 갈때의 최소 시간보다 크다면 pass
			if (dp[next][next_money] <= next_time) continue;

			// 해당 공항에 최소시간으로 가는 비용보다 높은 비용으로 가는 방법들을
			// 최소시간으로 업데이트 해준다 (무의미한 계산을 막기 위함)
			for (int j = next_money; j <= M; j++) {
				if (dp[next][j] > next_time) {
					dp[next][j] = next_time;
				}
			}
            
            ticket next_ticket = { next_time, next, next_money };
			pq.push(next_ticket);
		}

	}
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
        for (int i = 0; i < 101; i++)
        {
            airport[i].clear();
        }
        memset(dp, 0xFF, sizeof(dp));
	    ans = 0xFFFFFFFF;

        scanf("%d%d%d", &N, &M, &K);

		for (int i = 0; i < K; i++)
		{
            scanf("%d%d%d%d", &u, &v, &c, &d);
            ticket t = {d, v, c};
			airport[u].push_back(t); // 시간, 도착지, 비용
		}

		dijkstra();

		for (int i = 1; i <= M; i++) 
			ans = min(ans, dp[N][i]);

		if (ans == INF) {
            printf("Poor KCM\n");
        }
		else {
            printf("%u\n", ans);
        }

	}
}