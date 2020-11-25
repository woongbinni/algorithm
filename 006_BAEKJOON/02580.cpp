#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

int map[9][9];
bool col[9][9];
bool row[9][9];
bool squ[9][9];

void solve(int count)
{
    int x = count / 9;
    int y = count % 9;

    if (count == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    if(map[x][y] == 0){
        for(int i=1; i<=9; ++i){
            if(row[x][i] == false && col[y][i] == false && squ[(x/3)*3 + (y/3)][i] == false){
                row[x][i] = true;
                col[y][i] = true;
                squ[(x/3)*3 + (y/3)][i] = true;
                map[x][y] = i;
                solve(count + 1);
                row[x][i] = false;
                col[y][i] = false;
                squ[(x/3)*3 + (y/3)][i] = false;
                map[x][y] = 0;
            }
        }
    }
    else {
        solve(count + 1);
    }
}

int main()
{
    memset(col, false, sizeof(col));
    memset(row, false, sizeof(row));
    memset(squ, false, sizeof(squ));
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            scanf("%d", &(map[i][j]));
            if (map[i][j] != 0)
            {
                row[i][map[i][j]] = true;
                col[j][map[i][j]] = true;
                squ[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
            }
        }
    }

    solve(0);

    return 0;
}