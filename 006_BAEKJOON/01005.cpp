#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
 
#define MAX 1010
 
int N, K, D, W;
int buildTime[MAX];
int totalBuildTime[MAX];
int requiredCnt[MAX];
vector<int> buildOrder[MAX];
   
void solve()
{
    queue<int> bfs_queue;
    for (int i = 1; i <= N; i++)
    {
        if (requiredCnt[i] == 0)
        {
            bfs_queue.push(i);
            totalBuildTime[i] = buildTime[i];
        }
    }
 
    while (bfs_queue.empty() == 0)
    {
        int Cur = bfs_queue.front();
        bfs_queue.pop();
 
        for (unsigned int i = 0; i < buildOrder[Cur].size(); i++)
        {
            int nextItem = buildOrder[Cur][i];
            totalBuildTime[nextItem] = max(totalBuildTime[nextItem], totalBuildTime[Cur] + buildTime[nextItem]);
            requiredCnt[nextItem]--;
 
            if (requiredCnt[nextItem] == 0) bfs_queue.push(nextItem);
        }
    }

 }
  
int main()
{
    int T;
    scanf("%d", &T); 
    for (int tc = 1; tc <= T; tc++)
    {
        memset(buildTime, 0, sizeof(buildTime));
        memset(totalBuildTime, 0, sizeof(totalBuildTime));
        memset(requiredCnt, 0, sizeof(requiredCnt));
        for (int i = 0; i < MAX; i++) buildOrder[i].clear();

        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &(buildTime[i]));
        }
        for (int i = 0; i < K; i++)
        {
            int a, b; 
            scanf("%d%d", &a, &b);
            buildOrder[a].push_back(b);
            requiredCnt[b]++;
        }

        scanf("%d", &W);
        solve();
        printf("%d\n", totalBuildTime[W]);
    }
 
    return 0;
}