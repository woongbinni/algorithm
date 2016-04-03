#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char boggle[5][5];
bool snapshot_boggle[11][5][5];
int snapshot_cnt[11];

int dir_x[8] = { -1, 0, 1, 1, 1, 0, -1, -1};
int dir_y[8] = { -1, -1, -1, 0, 1, 1, 1, 0};

void boggle_snapshot(char* sample_str)
{
    for(int i=0; i<strlen(sample_str); ++i){
        for(int j=0; j<5; ++j){
            for(int k=0; k<5; ++k){
                if(boggle[j][k] == sample_str[i]){
                    snapshot_boggle[i][j][k] = true;
                }
            }
        }
    }
}

bool boggle_find_text(char* search_text, int search_idx, int cur_x, int cur_y)
{
    //printf("%s|%d|%d|%d\n", search_text, search_idx, cur_x, cur_y);
    if (cur_x < 0 || cur_x >= 5)
        return false;
    if (cur_y < 0 || cur_y >= 5)
        return false;
    if (snapshot_boggle[search_idx][cur_x][cur_y] == false) {
        return false;
    }
    if (strlen(&(search_text[search_idx])) == 1) {
        //printf("FOUND!!\n");
        return true;
    }
    return boggle_find_text(search_text, search_idx+1, cur_x+dir_x[0], cur_y+dir_y[0])
    ||boggle_find_text(search_text, search_idx+1, cur_x+dir_x[1], cur_y+dir_y[1])
    ||boggle_find_text(search_text, search_idx+1, cur_x+dir_x[2], cur_y+dir_y[2])
    ||boggle_find_text(search_text, search_idx+1, cur_x+dir_x[3], cur_y+dir_y[3])
    ||boggle_find_text(search_text, search_idx+1, cur_x+dir_x[4], cur_y+dir_y[4])
    ||boggle_find_text(search_text, search_idx+1, cur_x+dir_x[5], cur_y+dir_y[5])
    ||boggle_find_text(search_text, search_idx+1, cur_x+dir_x[6], cur_y+dir_y[6])
    ||boggle_find_text(search_text, search_idx+1, cur_x+dir_x[7], cur_y+dir_y[7]);
}

int main(void)
{
    int test_case = 0;
    char sample_str[11];
    int idx_i;

    scanf("%d", &test_case);

    for (idx_i = 0; idx_i < test_case; ++idx_i)
    {
        scanf("%s", &(boggle[0][0]));
        scanf("%s", &(boggle[1][0]));
        scanf("%s", &(boggle[2][0]));
        scanf("%s", &(boggle[3][0]));
        scanf("%s", &(boggle[4][0]));

        int sample_case;
        bool result;
        scanf("%d", &sample_case);

        for (int i = 0; i < sample_case; i++) {
            scanf("%s", sample_str);
            printf("%s ", sample_str);

            memset(snapshot_boggle, false, sizeof(snapshot_boggle));
            boggle_snapshot(sample_str);

            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    result = boggle_find_text(sample_str, 0, j, k);
                    if (result == true) {
                        break;
                    }
                }
                if(result == true) {
                    break;
                }
            }

            if (result == true) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }

        }
    }
    return 0;
}