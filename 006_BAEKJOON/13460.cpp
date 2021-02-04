#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <queue>

typedef struct _loc
{
    int red_y;
    int red_x;
    int blue_y;
    int blue_x;
    int distance;
} loc;

int N, M;
int hole_y, hole_x;
int ans;
char map[11][11];
bool visited[11][11][11][11];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main(void)
{
    loc start;
    queue<loc> bfs_queue;
    scanf("%d%d", &N, &M);

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= N; ++i)
    {
        char temp[11];
        scanf("%s", temp);
        for (int j = 1; j <= M; ++j)
        {
            map[i][j] = temp[j - 1];
            if (map[i][j] == 'R')
            {
                start.red_y = i;
                start.red_x = j;
                start.distance = 0;
            }
            if (map[i][j] == 'B')
            {
                start.blue_y = i;
                start.blue_x = j;
            }
            if (map[i][j] == 'O')
                hole_y = i, hole_x = j;
        }
    }

    bfs_queue.push(start);
    visited[start.red_y][start.red_x][start.blue_y][start.blue_x] = true;

    while (!bfs_queue.empty())
    {
        loc cur_loc = bfs_queue.front();
        bfs_queue.pop();

        if (cur_loc.distance > 10){
            ans = -1;
            break;
        }
        if (cur_loc.red_y == hole_y && cur_loc.red_x == hole_x)
        {
            ans = cur_loc.distance;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            loc next_loc;
            next_loc.red_y = cur_loc.red_y + dy[i];
            next_loc.red_x = cur_loc.red_x + dx[i];
            next_loc.distance = cur_loc.distance + 1;
            next_loc.blue_y = cur_loc.blue_y + dy[i];
            next_loc.blue_x = cur_loc.blue_x + dx[i];

            while (true)
            {
                if (map[next_loc.red_y][next_loc.red_x] == '#')
                {
                    next_loc.red_y -= dy[i];
                    next_loc.red_x -= dx[i];
                    break;
                }
                if (map[next_loc.red_y][next_loc.red_x] == 'O')
                {
                    break;
                }
                next_loc.red_y += dy[i];
                next_loc.red_x += dx[i];
            }

            while (true)
            {
                if (map[next_loc.blue_y][next_loc.blue_x] == '#')
                {
                    next_loc.blue_y -= dy[i];
                    next_loc.blue_x -= dx[i];
                    break;
                }
                if (map[next_loc.blue_y][next_loc.blue_x] == 'O')
                {
                    break;
                }
                next_loc.blue_y += dy[i];
                next_loc.blue_x += dx[i];
            }

            if (next_loc.blue_y == hole_y && next_loc.blue_x == hole_x)
            {
                continue;
            }

            if (next_loc.red_y == next_loc.blue_y && next_loc.red_x == next_loc.blue_x)
            {
                switch (i)
                {
                case 0:
                {
                    cur_loc.red_y > cur_loc.blue_y ? next_loc.red_y++ : next_loc.blue_y++;
                    break;
                }
                case 1:
                {
                    cur_loc.red_x < cur_loc.blue_x ? next_loc.red_x-- : next_loc.blue_x--;
                    break;
                }
                case 2:
                {
                    cur_loc.red_y < cur_loc.blue_y ? next_loc.red_y-- : next_loc.blue_y--;
                    break;
                }
                case 3:
                {
                    cur_loc.red_x > cur_loc.blue_x ? next_loc.red_x++ : next_loc.blue_x++;
                    break;
                }
                }
            }


            if (visited[next_loc.red_y][next_loc.red_x][next_loc.blue_y][next_loc.blue_x])
            {
                continue;
            }
            bfs_queue.push(next_loc);
            visited[next_loc.red_y][next_loc.red_x][next_loc.blue_y][next_loc.blue_x] = true;
        }
    }

    if(ans == 0){
        ans = -1;
    }

    printf("%d\n", ans);
    return 0;
}
