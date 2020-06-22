#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#include <queue>

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

typedef struct _point{
    int y;
    int x;
}point;

queue<point> points_queue;
int R, C;

void update_map(char map[51][51])
{
    char new_map[51][51];
    
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            new_map[i][j] = map[i][j];
        }
    }

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (map[i][j] == '*')
            {
                for(int k=0; k<4; ++k){
                    if (new_map[i + dy[k]][j + dx[k]] == '.')
                    {
                        new_map[i + dy[k]][j + dx[k]] = '*';
                    }
                }
            }
        }
    }

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            map[i][j] = new_map[i][j];
        }
    }
}

int main()
{
    char map[51][51];

    memset(map, 0x00, sizeof(map));
    scanf("%d%d", &R, &C);

    for (int i = 1; i <= R; ++i)
    {
        char temp[51];
        scanf("%s", temp);
        for (int j = 1; j <= C; ++j)
        {
            map[i][j] = temp[j - 1];
            if (map[i][j] == 'S')
            {
                point temp;
                temp.y = i;
                temp.x = j;
                points_queue.push(temp);
            }
        }
    }

    int ans = 0;
    while(true){
        ans += 1;

        if(points_queue.size() == 0){
            printf("KAKTUS\n");
            break;
        }

        update_map(map);
        int size = points_queue.size();
        for(int i=0; i<size; ++i){
            point pop = points_queue.front();
            points_queue.pop();
            for(int j=0; j<4; ++j){
                if (map[pop.y + dy[j]][pop.x + dx[j]] == '.'){
                    map[pop.y + dy[j]][pop.x + dx[j]] = 'S';
                    point temp;
                    temp.y = pop.y + dy[j];
                    temp.x = pop.x + dx[j];
                    points_queue.push(temp);
                }
                if (map[pop.y + dy[j]][pop.x + dx[j]] == 'D')
                {
                    printf("%d\n", ans);
                    return 0;
                }
            }
        }
    }
    return 0;
}