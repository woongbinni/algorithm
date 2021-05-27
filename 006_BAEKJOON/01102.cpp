#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
#include <cstring>

int N, P;
int map[17][17];
typedef struct _plant
{
    int on_status;
    int on_cnt;
    int cur_plant;
    int cost;
} plant;

queue<plant> bfs_queue;
unsigned int dp[1 << 16];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%d", &(map[i][j]));
        }
    }

    memset(dp, 0xFF, sizeof(dp));

    char cur_status_str[17];
    int cur_status = 0;
    int cur_cnt = 0;
    scanf("%s", cur_status_str);
    for (int i = 0; i < strlen(cur_status_str); ++i)
    {
        if (cur_status_str[i] == 'Y')
        {
            cur_status |= (1 << i);
            cur_cnt += 1;
        }
    }

    scanf("%d", &P);

    for (int i = 0; i < strlen(cur_status_str); ++i)
    {
        if (cur_status_str[i] == 'Y')
        {
            plant push_item = {cur_status, cur_cnt, i, 0};
            bfs_queue.push(push_item);
        }
    }

    while (!bfs_queue.empty())
    {
        plant pop = bfs_queue.front();
        // printf("%08X %d %d %d\n", pop.on_status, pop.on_cnt, pop.cur_plant, pop.cost);

        if (pop.on_cnt == P)
        {
            break;
        }

        bfs_queue.pop();

        for (int i = 0; i < N; ++i)
        {
            if ((pop.on_status & (0x01 << i)) != 0)
            { //이미 켜진 발전소...
                continue;
            }
            if (pop.cur_plant == i)
            {
                continue;
            }
            for (int j = 0; j < N; ++j)
            {
                if ((pop.on_status & (0x01 << j)) != 0)
                { //이미 켜진 발전소...
                    plant item = {(pop.on_status | (0x01 << i)), pop.on_cnt + 1, j, map[j][i] + pop.cost};
                    if (dp[(pop.on_status | (0x01 << i))] > map[j][i] + pop.cost)
                    {
                        dp[(pop.on_status | (0x01 << i))] = map[j][i] + pop.cost;
                        bfs_queue.push(item);
                        cur_cnt = item.on_cnt;
                    }
                }
            }
            if (cur_cnt > P)
            {
                break;
            }
        }
        if (cur_cnt > P)
        {
            break;
        }
    }

    unsigned int result = 0xFFFFFFFF;
    while (!bfs_queue.empty())
    {
        plant pop = bfs_queue.front();
        bfs_queue.pop();
        if (pop.cost < result)
        {
            result = pop.cost;
        }
    }
    if(result == 0xFFFFFFFF) {
        printf("-1\n");
    } else {
        printf("%llu\n", result);
    }

    return 0;
}